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
    INTV,
    SEMI,
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
        if (isalpha(c))
        {
            buffer += c;
            if (!isalpha(src.at(i + 1)))
            {
                cout << "Buffer: " << buffer << endl;
                if (buffer == "return")
                {
                    addToken(RETURN, buffer);
                }
                else
                {
                    addToken(IDENTIFIER, buffer);
                }
                buffer.clear();
            }
        }
        if (isdigit(c))
        {
            buffer += c;
            if (!isdigit(src.at(i + 1)))
            {
                cout << "Buffer: " << buffer << endl;
                addToken(INTV, buffer);
                buffer.clear();
            }
        }
        if (c == ';')
        {
            string s;
            s += c;
            addToken(SEMI, s);
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
    // converting to tokens
    tokenize(source);
    showTokens();

    return EXIT_SUCCESS;
}