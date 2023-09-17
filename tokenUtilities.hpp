#pragma once

enum TokenType
{
    // keywords
    RETURN = 0,
    INT,
    NUMBER,
    STRING,
    BOOL,
    VAR,
    FUNCTION,
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
    COMPLEX,
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
    std::optional<std::string> value;
};

std::vector<std::string> keywords = {
    "return",
    "int",
    "number",
    "string",
    "bool",
    "var",
    "function",
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
    "complex",
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
    "false"
    };

std::vector<std::string> symbols = {
    ";", "(", ")", "{", "}", "[", "]", "+",
    "-", "*", "/", "%", "^", ",", ".", "<",
    ">", "!", "="};

int find(std::vector<std::string> collection, std::string object)
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

std::string charToString(char c)
{
    std::string s;
    s += c;
    return s;
}