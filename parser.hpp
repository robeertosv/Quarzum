#pragma once

using namespace std;

class Parser
{
public:
    inline explicit Parser(vector<Token> input)
    {
        tokens = input;
    }

    optional<ExpressionNode> expr_node()
    {
        ExpressionNode expr;
        expr.token = next();

        // If the expression is not empty...
        if (expr.token.value.has_value())
        {
            return expr;
        }
        return {};
    }

    optional<ExitNode> exit_node()
    {
        ExitNode exit;
        // If there is an expression node with value...
        if (auto exprNode = expr_node() && next(2).type == SEMI)
        {
            optional<ExpressionNode> expr = expr_node();
            exit.exitCode = expr.value();
            return exit;
        }
        return {};
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
                if (next(2).type == EQUAL && next(4).type == SEMI)
                {
                    result.nodes.push_back(StatementNode{
                        IntAssignment{
                            next(), next(3)}});

                    cout << "Int assign: " << result.nodes.at(result.nodes.size() - 1).statement.value.value.value() << " -> " << result.nodes.at(result.nodes.size() - 1).statement.identifier.value.value() << endl;
                    i += 4;
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
    int l, i;
    Token next(int distance = 1)
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