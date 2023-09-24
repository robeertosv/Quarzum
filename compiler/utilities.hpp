#pragma once
using namespace std;

enum TokenType
{
    // Exit statements
    EXIT,
    RETURN,
    // Data types and keywords
    INT_LITERAL,
    INT_KEYWORD,
    STRING_LITERAL,
    STRING_KEYWORD,
    NUMBER_LITERAL,
    NUMBER_KEYWORD,
    BOOL_LITERAL,
    BOOL_KEYWORD,
    VAR_KEYWORD,
    FUNCTION_KEYWORD,
    NULL_KEYWORD,
    // Operators
    OPERATOR,
    // Others
    EQUAL,
    IDENTIFIER
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
