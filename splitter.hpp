#pragma once
using namespace std;

class Splitter
{
public:
    inline explicit Splitter(string src)
    {
        data = src;
    }
    vector<Token> split()
    {
        int l = data.length();
        line = 0;
        for (int i = 0; i < l; i++)
        {
            char c = data.at(i);
            char next;
            if (i + 1 < l)
            {
                next = data.at(i + 1);
            }
            // Token search
            if (c == ' ')
            {
                storeIfException(c);
            }
            else if (c == '\n')
            {
                line++;
                if (buffer[0] == '/' && buffer[1] == '/')
                {
                    buffer.clear();
                }
            }
            else if (c == '*' && next == '/' && buffer[0] == '/' && buffer[1] == '/')
            {
                buffer.clear();
            }
            else if (c == '/' && (next == '/' || next == '*'))
            {
                buffer += c;
                buffer += next;
            }
            else if (c == '"')
            {
                buffer += c;
                if (buffer[0] == '"' && buffer.length() > 1)
                {
                    addToken(STRINGV, buffer);
                }
            }
            else if (isalpha(c))
            {
                buffer += c;
                if (!isalpha(next) && isNotException())
                {
                    if (find(keywords, buffer) >= 0)
                    {
                        addToken(TokenType(find(keywords, buffer)));
                    }
                    else
                    {
                        addToken(IDENTIFIER, buffer);
                    }
                }
            }
            else if (ispunct(c))
            {
                storeIfException(c);
                if (find(symbols, charToString(c)) >= 0 && isNotException())
                {
                    addToken(TokenType(find(symbols, charToString(c)) + 200));
                }
            }
            else if (isdigit(c))
            {
                buffer += c;
                if (!isdigit(next) && isNotException())
                {
                    addToken(INTV, buffer);
                }
            }
            // Undefined symbol error
            else
            {
                cerr << "Error: undefined symbol at line " << line << ":" << endl;
                cerr << "-> " << data.substr(0, data.find("\n")) << endl;
                exit(EXIT_FAILURE);
            }
        }
        cout << "Splitting procedure finished." << endl;
        return tokens;
    }

private:
    vector<Token> tokens;
    string data, buffer;
    int line;

    void addToken(TokenType type, optional<string> value = "")
    {
        Token t;
        t.type = type;
        t.value = value;
        tokens.push_back(t);
        buffer.clear();
    }
    void storeIfException(char value)
    {
        if (buffer[0] == '"' || buffer[0] == '/')
        {
            buffer += value;
        }
    }
    bool isNotException()
    {
        return buffer[0] != '"' && buffer[0] != '/';
    }
};