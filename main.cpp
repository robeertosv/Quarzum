#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string getSource(string path)
{
    ifstream input(path);
    string source;
    while (!input.eof())
    {
        getline(input, source);
    }
    return source;
}

enum TokenType
{
    RETURN,
    INT,
    INTV,
    SEMI,
    EQUAL,
    IDENTIFIER
};

struct Token
{
    TokenType type;
    string value;
};

vector<Token> tokens;
void addToken(TokenType type, string value)
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
        char c = src.at(i);
        int line = 1;
        switch (c)
        {
        case ';':
            addToken(SEMI, ";");
            break;
        case '=':
            addToken(EQUAL, "=");
            break;
        default:
            if (isalpha(c))
            {
                buffer += c;
                if (!isalpha(src.at(i + 1)))
                {
                    cout << "Buffer: " << buffer << endl;

                    if (buffer == "return")
                    {
                        addToken(RETURN, buffer);
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
                if (!isdigit(src.at(i + 1)))
                {
                    cout << "Buffer: " << buffer << endl;
                    addToken(INTV, buffer);
                    buffer.clear();
                }
            }
            else if (isspace(c))
            {
                if (c == '\n')
                {
                    line++;
                }
                continue;
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
        cout << tokens.at(i).type << " | " << tokens.at(i).value << endl;
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