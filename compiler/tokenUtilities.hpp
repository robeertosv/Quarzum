#pragma once
using namespace std;
enum TokenType
{
    // keywords
    EXIT = 0,
    RETURN,
    DATATYPE,
    CONST,
    UNDEFINED,
    NULLV,
    IMPORT,
    FROM,
    IF,
    ELSE,
    WHILE,
    FOR,
    FOREACH,
    SWITCH,
    CONTINUE,
    BREAK,
    CASE,
    IN,
    MODULE,
    NOT,
    AND,
    OR,
    XOR,
    ENUM,
    CLASS,
    STRUCT,
    PUBLIC,
    PRIVATE,
    ASYNC,
    AWAIT,
    TRUE,
    FALSE,
    // values
    INTV = 100,
    STRINGV,
    NUMBERV,
    // symbols
    SEMI = 200,
    PAR_OPEN,
    PAR_CLOSE,
    CURLY_OPEN,
    CURLY_CLOSE,
    SQUARE_OPEN,
    SQUARE_CLOSE,
    PLUS,
    MINUS,
    PRODUCT,
    DIVIDE,
    DMODULE,
    POWER,
    COMMA,
    POINT,
    LESS,
    GREATER,
    NOT_SYMBOL,
    EQUAL,

    // composed symbols

    IS_EQUAL = 250,
    PLUS_UNARY,
    MINUS_UNARY,
    PLUS_EQUAL,
    MINUS_EQUAL,
    LESS_EQUAL,
    GREATER_EQUAL,
    NOT_EQUAL,
    PRODUCT_EQUAL,
    DIVIDE_EQUAL,
    DMODULE_EQUAL,
    // others
    IDENTIFIER = 300
};

struct Token
{
    TokenType type;
    optional<string> value;
};

vector<string> keywords = {
    "exit",
    "return",
    "const",
    "undefined",
    "null",
    "import",
    "from",
    "if",
    "else",
    "while",
    "for",
    "foreach",
    "switch",
    "continue",
    "break",
    "case",
    "in",
    "module",
    "not",
    "and",
    "or",
    "xor",
    "enum",
    "class",
    "struct",
    "public",
    "private",
    "async",
    "await",
    "true",
    "false"};

vector<string> data_types = {
    "int",
    "number",
    "string",
    "bool",
    "var",
    "function",
    "complex"};

vector<string> symbols = {
    ";", "(", ")", "{", "}", "[", "]", "+",
    "-", "*", "/", "%", "^", ",", ".", "<",
    ">", "!", "="};

int find(vector<string> collection, string object)
{
    int l = collection.size();
    for (int i = 0; i < l; i++)
    {
        if (object == collection.at(i))
        {
            return i;
        }
    }
    return -1;
}

string charToString(char c)
{
    string s;
    s += c;
    return s;
}