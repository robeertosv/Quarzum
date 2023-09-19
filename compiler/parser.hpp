#pragma once

using namespace std;

class Parser
{
public:
    inline explicit Parser(vector<Token> input)
    {
        tokens = input;
    }

    SyntaxTree parse()
    {
        l = tokens.size();
        i = 0;
        while (i < l)
        {
            Token token = tokens.at(i);
            switch (token.type)
            {
            }
            i++;
        }
        cout << "Parsing procedure finished." << endl;
        return result;
    }

private:
    SyntaxTree result;
    vector<Token> tokens;
    unsigned int l, i;
    Token next(short int distance = 1)
    {
        if (i + distance < l)
        {
            return tokens.at(i + distance);
        }
        return {};
    };
    void abort()
    {
        cerr << "Error: invalid syntax" << endl;
        exit(EXIT_FAILURE);
    }
};