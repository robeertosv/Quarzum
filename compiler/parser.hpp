#pragma once

class Parser
{
public:
    Parser(deque<Token> tokens) : m_tokens(move(tokens)) {}

    std::experimental::optional<Expr> parse_expr()
    {
        if (next().type == INT_LITERAL)
        {
            return Expr{next()};
        }
        return {};
    }

    ExitStatement parse()
    {
        /* Converts tokens into an AST */
        while (i < size)
        {
            t = m_tokens.at(i);
            switch (t.type)
            {
            case EXIT:
                if (auto expr = parse_expr())
                {
                    tree = ExitStatement{expr.value()};
                }
                else
                {
                    error();
                }
                break;

            default:
                break;
            }
            ++i;
        }
        return tree;
    }

private:
    deque<Token> m_tokens;
    Token t;
    unsigned int i = 0;
    unsigned int size = m_tokens.size();
    ExitStatement tree;

    void error()
    {
        /* Shows a Syntax Error message */
        cout << "Syntax Error \n";
        exit(EXIT_FAILURE);
    }

    Token next(short unsigned int distance = 1)
    {
        /* Returns the next token in the list, if it exists */
        if (i + distance < size)
        {
            return m_tokens.at(i + distance);
        }
        return {};
    }
};
