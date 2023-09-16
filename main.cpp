#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "tokenType.h"

using namespace std;

string getSource(string path)
{
    ifstream input(path);
    string source;
    string line;
    while (getline(input, line))
    {
        source += line + "\n";
    }
    return source;
}

struct Token
{
    TokenType type;
    optional<string> value;
};

vector<Token> tokens;
void addToken(TokenType type, optional<string> value = "")
{
    Token t;
    t.type = type;
    t.value = value;
    tokens.push_back(t);
}

void tokenize(string src)
{
    int length = src.length();
    string buffer;
    for (int i = 0; i < length; i++)
    {
        // some information about scanning
        char c = src.at(i);
        char next;
        if (i + 1 < length)
        {
            next = src.at(i + 1);
        }
        int line = 1;

        // scanning by characters
        switch (c)
        {
        case ' ':
            break;
        case '\n':
            line++;
            break;
        case ';':
            addToken(SEMI);
            break;
        case '=':
            buffer += "=";
            if (next != '=')
            {
                if (buffer == "=")
                {
                    addToken(EQUAL);
                }
                if (buffer == "==")
                {
                    addToken(IS_EQUAL);
                }
                if (buffer == "===")
                {
                    addToken(IS_EQUIVALENT);
                }
                buffer.clear();
            }
            break;
        default:
            if (isalpha(c))
            {
                buffer += c;
                if (!isalpha(next))
                {
                    if (buffer == "return")
                    {
                        addToken(RETURN);
                        buffer.clear();
                    }
                    else if (buffer == "int")
                    {
                        addToken(INT);
                        buffer.clear();
                    }
                    else
                    {
                        addToken(IDENTIFIER, buffer);
                        buffer.clear();
                    }
                }
            }
            else if (isdigit(c))
            {
                buffer += c;
                if (!isdigit(next))
                {
                    addToken(INTV, buffer);
                    buffer.clear();
                }
            }
            else
            {
                cerr << "Error: undefined symbol at line " << line << ":" << endl;
                cerr << "-> " << src.substr(0, src.find("\n")) << endl;
                exit(EXIT_FAILURE);
            }
            break;
        }
    }
};

void showTokens()
{
    cout << "Tokens: " << tokens.size() << endl;
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << toString(tokens.at(i).type);
        if (tokens.at(i).value != "")
        {
            cout << " | " << tokens.at(i).value.value();
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Error: Not enough arguments." << endl;
        return EXIT_FAILURE;
    }

    cout << "Compiling " << argv[1] << "..." << endl;

    // reading the source file
    string source = getSource(argv[1]);
    cout << source << endl;
    // converting to tokens
    tokenize(source);
    showTokens();

    return EXIT_SUCCESS;
}