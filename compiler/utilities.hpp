#pragma once
using namespace std;

bool isOperator(char value)
{
    return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == '^');
};
struct Token
{
    TokenType type;
    string value;
};
struct Operator
{
    TokenType op;
};

struct Expr
{
    Token literal;
};

struct Exit
{
    Expr value;
};

struct Assign
{
    TokenType type;
    Token ident;
    Expr value;
};
struct ReAssign
{
    Token ident;
    Expr value;
};

struct Root
{
    deque<Exit> childs;
};
