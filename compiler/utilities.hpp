#pragma once
using namespace std;

bool isOperator(char value)
{
    return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == '^');
};
bool isSizeModifier(string value)
{
    return (value == "x8" || value == "x16" || value == "x32" || value == "x64");
};
std::map<string, int> keywords = {
    {"exit", 0},
    {"return", 1},
    {"int", 3},
    {"string", 5},
    {"number", 7},
    {"true", 8},
    {"false", 9},
    {"bool", 10},
    {"var", 11},
    {"function", 12},
    {"null", 13},
    {"struct", 14},
    {"enum", 15},
    {"class", 16},
    {"public", 17},
    {"private", 18},
    {"module", 19},
    {"const", 35},
    {"unsigned", 36},
    {"short", 37},
    {"long", 38},
};
int findKeyword(string keyword)
{
    return keywords.at(keyword);
}
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
