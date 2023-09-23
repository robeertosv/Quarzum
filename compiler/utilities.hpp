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
