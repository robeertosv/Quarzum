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
            case INT:
                if (next().type == IDENTIFIER)
                {
                    if (next(2).type == SEMI)
                    {
                        result.nodes.push_back(StatementNode{
                            Assignment{next(), Token{UNDEFINED}}});
                        cout << "Variable declaration without value\n";
                    }
                    else if (next(2).type == EQUAL)
                    {
                        if (next(3).type == INTV)
                        {
                            Expression expr = {next(3)};
                            result.nodes.push_back(StatementNode{
                                Assignment{next(), expr}});
                            cout << "Variable declaration with value\n";
                        }
                        else
                        {
                            abort();
                        }
                    }
                    else
                    {
                        abort();
                    }
                }
                else
                {
                    abort();
                }
                break;
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