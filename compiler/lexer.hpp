#pragma once
deque<Token> tokenize(string source)
{
    /* Divides the string into single tokens */
    deque<Token> tokens;
    short unsigned int size, line, i = 0;
    size = source.length();
    string buffer;
    bool isEOF = false;
    char c;
    while (i < size)
    {
        c = source.at(i);
        if (i + 1 > size)
        {
            isEOF = true;
        }
        if (c == '\n')
        {
            line++;
        }
        else if (isalpha(c))
        {
            buffer += c;
            if (!isEOF && !isalnum(source.at(i + 1)))
            {
                if (buffer == "exit")
                {
                    tokens.push_back({EXIT, "exit"});
                }
                else
                {
                    tokens.push_back({IDENTIFIER, buffer});
                }
                buffer.clear();
            }
        }
        else if (isdigit(c))
        {
            buffer += c;
            if (!isEOF && !isdigit(source.at(i + 1)))
            {
                tokens.push_back({INT_LITERAL, buffer});
                buffer.clear();
            }
        }
        else if (ispunct(c))
        {
            // in developement
        }
        else if (!isspace(c))
        {
            cout << "Lexical error in line " << line << endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }
    return tokens;
}