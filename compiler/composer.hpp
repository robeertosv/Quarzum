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
            case PLUS:
                if (next().type == PLUS)
                {
                    composeToken(PLUS_UNARY);
                    i++;
                }
                else
                {
                    composeIf(PLUS, EQUAL, PLUS_EQUAL);
                }
                break;
            case MINUS:
                if (next().type == MINUS)
                {
                    composeToken(MINUS_UNARY);
                    i++;
                }
                else
                {
                    composeIf(MINUS, EQUAL, MINUS_EQUAL);
                }
                break;
            case PRODUCT:
                composeIf(PRODUCT, EQUAL, PRODUCT_EQUAL);
                break;
            case DIVIDE:
                composeIf(DIVIDE, EQUAL, DIVIDE_EQUAL);
                break;
            case DMODULE:
                composeIf(DMODULE, EQUAL, DMODULE_EQUAL);
                break;
            case POWER:
                composeIf(POWER, EQUAL, POWER_EQUAL);
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
    void composeToken(TokenType type)
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