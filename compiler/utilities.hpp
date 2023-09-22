#pragma once
using namespace std;

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

struct Expr
{
    Token literal;
};

struct ExitStatement
{
    Expr value;
};