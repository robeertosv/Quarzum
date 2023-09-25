
#pragma once
class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}

    experimental::optional<Expr> parse_expr(unsigned short int distance = 1)
    {
        if (next(distance).type == INT_LITERAL)
        {
            return Expr{next()};
        }
        return {};
    }

    Root parse()
    {
        /* Converts tokens into an AST */
        while (i < size)
        {
            t = m_tokens.get(i);
            switch (t.type)
            {
            case EXIT:
                if (auto expr = parse_expr())
                {
                    tree.childs.push_back(Exit{expr.value()});
                }
                else
                {
                    throwError(SYNTAX_ERROR);
                }
                break;
            case INT_KEYWORD:
                if (next().type == IDENTIFIER)
                {
                    if (next(2).type == EQUAL)
                    {
                        if (auto expr = parse_expr(3))
                        {
                            // Push-back an int assign with value
                        }
                    }
                    else
                    {
                        // Push-back an int assign without value
                    }
                }
            default:
                break;
            }
            ++i;
        }
        return tree;
    }

private:
    TokenList m_tokens;
    Token t;
    unsigned int i = 0;
    unsigned int size = m_tokens.size();
    Root tree;
    Token next(short unsigned int distance = 1)
    {
        return m_tokens.get(i + distance);
    }
};
