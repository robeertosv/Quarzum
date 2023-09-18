#pragma once

using namespace std;

class Composer
{

public:
    inline explicit Composer(vector<Token> tokens)
    {
        list = tokens;
    }
    vector<Token> compose()
    {
        l = list.size();
        i = 0;
        while (i < l)
        {
            token = list.at(i);
            switch (token.type)
            {
            case NOT_SYMBOL:
                composeIf(NOT, EQUAL, NOT_EQUAL);
                break;
            case LESS:
                composeIf(LESS, EQUAL, LESS_EQUAL);
                break;
            case GREATER:
                composeIf(GREATER, EQUAL, GREATER_EQUAL);
                break;
            case OPERATOR:
                if (token.value.value() == "*")
                {
                    composeIf(OPERATOR, EQUAL, PRODUCT_EQUAL, token.value.value());
                }
                else if (token.value.value() == "/")
                {
                    composeIf(OPERATOR, EQUAL, DIVIDE_EQUAL, token.value.value());
                }
                else if (token.value.value() == "+")
                {
                    if (next().value.value() == "+")
                    {
                        composeToken(PLUS_UNARY);
                        i++;
                    }
                    else
                    {
                        composeIf(OPERATOR, EQUAL, PLUS_EQUAL, token.value.value());
                    }
                }
                else if (token.value.value() == "-")
                {
                    if (next().value.value() == "-")
                    {
                        composeToken(MINUS_UNARY);
                        i++;
                    }
                    else
                    {
                        composeIf(OPERATOR, EQUAL, MINUS_EQUAL, token.value.value());
                    }
                }
                else if (token.value.value() == "%")
                {
                    composeIf(OPERATOR, EQUAL, DMODULE_EQUAL, token.value.value());
                }
                else if (token.value.value() == "^")
                {
                    composeIf(OPERATOR, EQUAL, POWER_EQUAL, token.value.value());
                }
                break;
            case EQUAL:
                composeIf(EQUAL, EQUAL, IS_EQUAL);
                break;
            case INTV:
                if (next().type == POINT && next(2).type == INTV)
                {
                    composeToken(NUMBERV, token.value.value() + "." + next(2).value.value());
                    i += 2;
                }
                else
                {
                    composeToken(INTV, token.value.value());
                }
                break;
            default:
                // Add the single token if is not combinable
                composeToken(token.type, token.value);
                break;
            }
            i++;
        }
        return composedList;
    }

private:
    vector<Token> list;
    vector<Token> composedList;
    unsigned int l, i;
    Token token;
    Token next(short int distance = 1)
    {
        if (i + distance < l)
        {
            return list.at(i + distance);
        }
        return {};
    }
    void composeToken(TokenType type, optional<string> value = "")
    {
        Token composed;
        composed.type = type;
        composed.value = value;
        composedList.push_back(composed);
    }
    void composeIf(TokenType def, TokenType nextType, TokenType result, optional<string> value = "")
    {
        if (next().type == nextType)
        {
            composeToken(result);
            i++;
        }
        else
        {
            composeToken(def, value);
        }
    }
};