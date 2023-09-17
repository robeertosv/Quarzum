#pragma once

using namespace std;

class Parser
{
public:
    inline explicit Parser(vector<Token> input)
    {
        tokens = input;
    }
    optional<ExpressionNode> parse_expr()
    {
    }
    optional<ReturnNode> parse()
    {
        l = tokens.size();
        i = 0;
        while (i < l)
        {
            Token token = tokens.at(i);
            if (token.type == RETURN)
            {

                ReturnNode node;
                ExpressionNode n;
                n.intv = next();
                node.expr = n;
                result = node;
                cout << "RETURN-EXPR( " << node.expr.intv.value.value() << " )" << endl;
            }
            i++;
        }
        return result;
    }

private:
    vector<Token> tokens;

    int l, i;
    Token next(int distance = 1)
    {
        if (i + distance < l)
        {
            return tokens.at(i + distance);
        }
        return {};
    };
    optional<ReturnNode> result;
};