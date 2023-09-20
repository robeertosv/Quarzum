#pragma once
using namespace std;
enum TokenType
{
    // keywords
    EXIT = 0,
    RETURN,
    INT, // MIN_DATATYPE_INDEX (2)
    NUMBER,
    STRING,
    BOOL,
    VAR, // MAX_DATATYPE_INDEX (6)
    FUNCTION,
    CONST,
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
    UNSIGNED,
    // values
    INTV,
    TRUE,
    FALSE,
    NULLV,
    UNDEFINED,
    NUMBERV,
    STRINGV,

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
    POWER_EQUAL,
    // others
    IDENTIFIER = 300
};

struct Token
{
    TokenType type;
    optional<string> value;
};

string keywords[] = {
    "exit",
    "return",
    "int",
    "number",
    "string",
    "bool",
    "var",
    "complex",
    "function",
    "const",
    "unsigned",
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
    "false",
    "null",
    "undefined"};

string symbols[] = {
    ";", "(", ")", "{", "}", "[", "]", "+", "-", "*", "/", "%", "^", ",", ".", "<",
    ">", "!", "="};

short int find(string collection[], const string object)
{
    int l = collection->length();
    for (unsigned short int i = 0; i < l; ++i)
    {
        if (object == collection[i])
        {
            return i;
        }
    }
    return -1;
}
const short unsigned int MIN_DATATYPE_INDEX{2};
const short unsigned int MAX_DATATYPE_INDEX{6};
bool isDataType(TokenType tokenIndex)
{
    return (tokenIndex >= MIN_DATATYPE_INDEX && tokenIndex <= MAX_DATATYPE_INDEX);
}
const short unsigned int MIN_DATAVALUE_INDEX{34};
const short unsigned int MAX_DATAVALUE_INDEX{40};
bool isDataValue(TokenType tokenIndex)
{
    return (tokenIndex >= MIN_DATAVALUE_INDEX && tokenIndex <= MAX_DATAVALUE_INDEX);
}

string charToString(const char c)
{
    string s(1, c);
    return s;
}