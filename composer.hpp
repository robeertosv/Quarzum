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
        cout << "Composing..." << endl;
        i = 0;
        while (i < l)
        {
            token = list.at(i);
            switch (token.type)
            {
            case PLUS:
                composeIf(PLUS, PLUS_UNARY);
                composeIf(EQUAL, PLUS_EQUAL);
                break;
            case MINUS:
                composeIf(MINUS, MINUS_UNARY);
                composeIf(EQUAL, MINUS_EQUAL);
                break;
            case LESS:
                composeIf(EQUAL, LESS_EQUAL);
                break;
            case GREATER:
                composeIf(EQUAL, GREATER_EQUAL);
                break;
            // case EQUAL:
            //     if (i + 1 < l && list.at(i + 1) == EQUAL)
            //     {
            //         if (i + 2 < l && list.at(i + 2).type == EQUAL)
            //         {
            //             composeToken(IS_EQUIVALENT);
            //             i += 2;
            //         }
            //         else
            //         {
            //             composeToken(IS_EQUAL);
            //             i++;
            //         }
            //     }
            //     else
            //     {
            //         composeToken(EQUAL);
            //     }
            //     break;

            // case INTV:
            //     if (i + 2 < l && list.at(i + 1) == POINT && list.at(i + 2).type == INTV)
            //     {
            //         composeToken(NUMBERV, list.at(i).value.value() + "." + list.at(i + 2).value.value());
            //         i++;
            //     }
            //     else
            //     {
            //         composeToken(INTV, list.at(i).value);
            //     }
            //     break;
            default:
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

    void composeToken(TokenType type, optional<string> value = "")
    {
        Token composed;
        composed.type = type;
        composed.value = value;
        composedList.push_back(composed);
    }
    void composeIf(TokenType nextState, TokenType response)
    {
        if (i + 1 < l && list.at(i + 1).type == nextState)
        {
            composeToken(response);
        }
        i++;
    }
};