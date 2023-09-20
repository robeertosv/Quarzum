#pragma once

using namespace std;

class Parser
{
public:
    inline explicit Parser(vector<Token> input) : tokens(move(input))
    {
    }

    SyntaxTree parse()
    {
        l = tokens.size();
        i = 0;
        while (i < l)
        {
            Token token = tokens.at(i);

            if (isDataType(token.type))
            {
                createAssign(token.type);
            }

            ++i;
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
    void createAssign(TokenType type)
    {
        bool isValid = false;
        if (next().type == IDENTIFIER)
        {
            cout << "Variable declaration" << endl;
            if (next(2).type == SEMI)
            {
                isValid = true;
                result.nodes.push_back(StatementNode{
                    Assignment{type, next(), Token{UNDEFINED}}});
            }
            else if (next(2).type == EQUAL && isDataValue(next(3).type))
            {
                isValid = true;
                Expression expr = {next(3)};
                result.nodes.push_back(StatementNode{
                    Assignment{type, next(), expr}});
            }
        }
        if (isValid == false)
        {
            abort();
        }
    }
};