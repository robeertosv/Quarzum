#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "tokenUtilities.h"

using namespace std;

vector<Token> tokens;
void addToken(TokenType type, optional<string> value = "")
{
    Token t;
    t.type = type;
    t.value = value;
    tokens.push_back(t);
}

void split(string src)
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

        if (c == ' ')
        {
            if (buffer[0] == '"')
            {
                buffer += c;
            }
        }
        else if (c == '\n')
        {
            line++;
        }
        else if (c == '=')
        {
            addToken(EQUAL);
        }
        else if (c == '"')
        {
            buffer += c;
            if (buffer[0] == '"' && buffer.length() > 1)
            {
                addToken(STRINGV, buffer);
            }
        }

        // Keywords and identifiers
        else if (isalpha(c))
        {

            buffer += c;
            if (!isalpha(next) && buffer[0] != '"')
            {
                if (find(keywords, buffer) >= 0)
                {
                    addToken(TokenType(find(keywords, buffer)));
                    buffer.clear();
                }
                else
                {
                    addToken(IDENTIFIER, buffer);
                    buffer.clear();
                }
            }
        }
        // Some punctuation symbols
        else if (ispunct(c))
        {
            if (buffer[0] == '"')
            {
                buffer += c;
            }
            else if (find(symbols, charToString(c)) >= 0)
            {
                addToken(TokenType(find(symbols, charToString(c)) + 200));
            }
        }
        // Int
        else if (isdigit(c))
        {
            buffer += c;
            if (!isdigit(next) && buffer[0] != '"')
            {
                addToken(INTV, buffer);
                buffer.clear();
            }
        }
        // Undefined symbol error
        else
        {
            cerr << "Error: undefined symbol at line " << line << ":" << endl;
            cerr << "-> " << src.substr(0, src.find("\n")) << endl;
            exit(EXIT_FAILURE);
        }
    }
};

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

vector<Token> composedTokens;
void composeToken(TokenType type, optional<string> value = "")
{
    Token composed;
    composed.type = type;
    composed.value = value;
    composedTokens.push_back(composed);
}
void compose(vector<Token> tokens)
{
    int l = tokens.size();
    for (int i = 0; i < l; i++)
    {
        TokenType token = tokens.at(i).type;
        TokenType next;
        if (i + 1 < l)
        {
            next = tokens.at(i + 1).type;
        }
        else
        {
            next = NONE;
        }
        string buffer;
        switch (token)
        {
        case PLUS:
            if (next == PLUS)
            {
                composeToken(PLUS_UNARY);
                i++;
            }
            if (next == EQUAL)
            {
                composeToken(PLUS_EQUAL);
                i++;
            }
            break;
        case MINUS:
            if (next == MINUS)
            {
                composeToken(MINUS_UNARY);
                i++;
            }
            if (next == EQUAL)
            {
                composeToken(MINUS_EQUAL);
                i++;
            }
            break;
        case EQUAL:
            if (next == EQUAL)
            {
                if (i + 2 < l && tokens.at(i + 2).type == EQUAL)
                {
                    composeToken(IS_EQUIVALENT);
                    i += 2;
                }
                else
                {
                    composeToken(IS_EQUAL);
                    i++;
                }
            }
            else
            {
                composeToken(EQUAL);
            }
            break;
        case LESS:
            if (next == EQUAL)
            {
                composeToken(LESS_EQUAL);
                i++;
            }
            break;
        case GREATER:
            if (next == EQUAL)
            {
                composeToken(GREATER_EQUAL);
                i++;
            }
            break;
        case INTV:
            if (next == POINT && tokens.at(i + 2).type == INTV)
            {
                composeToken(NUMBERV, tokens.at(i).value.value() + "." + tokens.at(i + 2).value.value());
                i++;
            }
            else
            {
                composeToken(INTV, tokens.at(i).value);
            }
            break;
        default:
            composeToken(token, tokens.at(i).value);
            break;
        }
    }
}
void showComposedTokens()
{
    cout << endl
         << "Composed Tokens: " << composedTokens.size() << endl;
    for (int i = 0; i < composedTokens.size(); i++)
    {
        cout << toString(composedTokens.at(i).type);
        if (composedTokens.at(i).value != "")
        {
            cout << " | " << composedTokens.at(i).value.value();
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
    // converting to simple tokens
    split(source);
    // merging simple tokens to composed ones
    compose(tokens);
    showComposedTokens();
    return EXIT_SUCCESS;
}