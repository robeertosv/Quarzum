#pragma once
class Lexer
{
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        /* Divides the string into single tokens */
        size = m_src.length();
        while (i < size)
        {
            c = m_src.at(i);
            if (c == '\n')
            {
                line++;
            }
            else if (c == '"')
            {
                buffer += c;
                if (buffer[0] == '"' && buffer.length() > 1)
                {
                    addToken(STRING_LITERAL, buffer);
                }
            }
            else if (isalpha(c))
            {
                buffer += c;
                if (!isException() && !isEOF() && !isalnum(next()))
                {
                    if (buffer == "exit")
                    {
                        addToken(EXIT, "exit");
                    }
                    else if (buffer == "int")
                    {
                        addToken(INT_KEYWORD, "int");
                    }
                    else if (buffer == "import")
                    {
                        addToken(IMPORT, "import");
                    }
                    else if (buffer == "from")
                    {
                        addToken(FROM, "from");
                    }
                    else
                    {
                        addToken(IDENTIFIER, buffer);
                    }
                }
            }
            else if (isdigit(c))
            {
                buffer += c;
                if (!isException() && !isEOF() && !isdigit(next()))
                {
                    addToken(INT_LITERAL, buffer);
                }
            }
            else if (ispunct(c))
            {
                // in developement
                if (isException())
                {
                    buffer += c;
                }
                else if (c == '=')
                {
                    addToken(EQUAL, "=");
                }
                else if (isOperator(c))
                {
                    string s(c, 1);
                    addToken(OPERATOR, s);
                }
            }
            else if (!isException() && !isspace(c))
            {
                throwError(UNEXPECTED_TOKEN);
            }
            i++;
        }
        return tokens;
    }

private:
    string m_src;
    TokenList tokens;
    unsigned int size, line, i = 0;
    string buffer;
    bool isEOF()
    {
        /* Returns true if m_src[i] is the final character */
        return i + 1 > size;
    };
    char c;
    char next(short unsigned int distance = 1)
    {
        /* Returns the next character if it exists*/
        if (i + distance < size)
        {
            return m_src.at(i + distance);
        }
        return {};
    }
    void addToken(TokenType type, string value)
    {
        /* Adds a new token to the deque */
        tokens.addToken(type, value);
        buffer.clear();
    }
    bool isException()
    {
        return buffer[0] == '"';
    }
};
