#pragma once
using namespace std;

class Splitter
{
public:
    inline explicit Splitter(string src) : data(move(src))
    {
    }
    deque<Token> split()
    {
        l = data.length();
        line = 0;
        while (i < l)
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
                buffer += c + next;
            }
            else if (c == '"')
            {
                buffer += c;
                if (buffer.length() > 1 && buffer[0] == '"')
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
                if (isNotException() && find(symbols, charToString(c)) >= 0)
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
            ++i;
        }
        return tokens;
    }

private:
    deque<Token> tokens;
    string data, buffer;
    unsigned int line, l, i;

    void addToken(TokenType type, optional<string> value = "")
    {
        tokens.push_back(Token{type, value});
        buffer.clear();
    }
    bool isNotException()
    {
        return buffer[0] != '"' && buffer[0] != '/';
    }
    void storeIfException(const char value)
    {
        if (!isNotException())
        {
            buffer += value;
        }
    }
};