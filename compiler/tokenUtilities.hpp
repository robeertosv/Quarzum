#pragma once
using namespace std;
enum TokenType
{
    // keywords
    EXIT = 0,
    RETURN,
    INT,  // MIN_DATATYPE_INDEX (2)
          // NUMBER,
          // STRING,
          // BOOL,
          // VAR, // MAX_DATATYPE_INDEX (6)
          // FUNCTION,
          // CONST,
          // IMPORT,
          // FROM,
          // IF,
          // ELSE,
          // WHILE,
          // FOR,
          // FOREACH,
          // SWITCH,
          // CONTINUE,
          // BREAK,
          // CASE,
          // IN,
          // MODULE,
          // NOT,
          // AND,
          // OR,
          // XOR,
          // ENUM,
          // CLASS,
          // STRUCT,
          // PUBLIC,
          // PRIVATE,
          // ASYNC,
          // AWAIT,
          // UNSIGNED,
          // values
    INTV, // MIN_DATAVALUE_INDEX (34)
    TRUE,
    FALSE,
    NULLV,
    UNDEFINED,
    NUMBERV,
    STRINGV, // MAX_DATAVALUE_INDEX(40)

    // symbols
    SEMI = 200,
    PAR_OPEN,
    PAR_CLOSE,
    CURLY_OPEN,
    CURLY_CLOSE,
    SQUARE_OPEN,
    SQUARE_CLOSE,
    PLUS,
    // MINUS,
    // PRODUCT,
    // DIVIDE,
    // DMODULE,
    // POWER,
    // COMMA,
    POINT,
    // LESS,
    // GREATER,
    // NOT_SYMBOL,
    EQUAL,

    // composed symbols

    IS_EQUAL = 250,
    // PLUS_UNARY,
    //  MINUS_UNARY,
    //  PLUS_EQUAL,
    //  MINUS_EQUAL,
    //  LESS_EQUAL,
    //  GREATER_EQUAL,
    //  NOT_EQUAL,
    //  PRODUCT_EQUAL,
    //  DIVIDE_EQUAL,
    //  DMODULE_EQUAL,
    //  POWER_EQUAL,
    //  others
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
    "int"};

string symbols[] = {
    ";", "(", ")", "{", "}", "[", "]", "+", "-", "*", "/", "%", "^", ",", ".", "<",
    ">", "!", "="};

short int find(string collection[], const string object)
{
    int l = collection->size();
    for (unsigned short int i = 0; i < l; ++i)
    {
        if (object == collection[i])
        {
            return i;
        }
    }
    return -1;
}
const short unsigned int MIN_DATATYPE_INDEX{TokenType(INT)};
const short unsigned int MAX_DATATYPE_INDEX{TokenType(INT) + 1};
bool isDataType(TokenType tokenIndex)
{
    return (tokenIndex >= MIN_DATATYPE_INDEX && tokenIndex <= MAX_DATATYPE_INDEX);
}
const short unsigned int MIN_DATAVALUE_INDEX{TokenType(INTV)};
const short unsigned int MAX_DATAVALUE_INDEX{TokenType(INTV) + 1};
bool isDataValue(TokenType tokenIndex)
{
    return (tokenIndex >= MIN_DATAVALUE_INDEX && tokenIndex <= MAX_DATAVALUE_INDEX);
}

string charToString(const char c)
{
    string s(1, c);
    return s;
}