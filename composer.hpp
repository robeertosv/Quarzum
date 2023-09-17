#pragma once
#include <vector>
#include <optional>
#include <string>
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
        cout << "Composing..." << endl
             << "------------" << endl;
        i = 0;
        while (i < l)
        {
            token = list.at(i);
            switch (token.type)
            {
            case PLUS:
                if (next().type == PLUS)
                {
                    composeToken(PLUS_UNARY);
                    i++;
                }
                else if (next().type == EQUAL)
                {
                    composeToken(PLUS_EQUAL);
                    i++;
                }
                else
                {
                    composeToken(PLUS);
                }
                break;
            case MINUS:
                if (next().type == MINUS)
                {
                    composeToken(MINUS_UNARY);
                    i++;
                }
                else if (next().type == EQUAL)
                {
                    composeToken(MINUS_EQUAL);
                    i++;
                }
                else
                {
                    composeToken(MINUS);
                }
                break;
            case EQUAL:
                if (next().type == EQUAL)
                {
                    composeToken(IS_EQUAL);
                    i++;
                }
                else
                {
                    composeToken(MINUS);
                }
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
    int l, i;
    Token token;
    Token next(int distance = 1)
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
};