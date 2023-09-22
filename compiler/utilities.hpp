#pragma once
using namespace std;
#include <string>

enum TokenType
{
    EXIT,
    INT_LITERAL,
    IDENTIFIER
};

struct Token
{
    TokenType type;
    string value;
};