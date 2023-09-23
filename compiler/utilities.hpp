#pragma once
using namespace std;

enum TokenType
{
    EXIT,
    INT_LITERAL,
    INT_KEYWORD,
    EQUAL,
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

struct IntAssign
{
    Expr value;
};

struct Root
{
    deque<ExitStatement> childs;
};
