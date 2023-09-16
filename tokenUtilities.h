enum TokenType
{
    // keywords
    RETURN = 0,
    INT = 1,
    NUMBER = 2,
    STRING = 3,
    BOOL = 4,
    ANY = 5,
    FUNCTION = 6,
    CONST = 7,
    UNDEFINED = 8,
    NULLV = 9,
    IMPORT = 10,
    FROM = 11,
    IF = 12,
    ELSE = 13,
    WHILE = 14,
    FOR = 15,
    FOREACH = 16,
    SWITCH = 17,
    CONTINUE = 18,
    BREAK = 19,
    CASE = 20,
    IN = 21,
    MODULE = 22,
    COMPLEX = 23,
    NOT = 24,
    AND = 25,
    OR = 26,
    XOR = 27,
    ENUM = 28,
    CLASS = 29,
    STRUCT = 30,
    PUBLIC = 31,
    PRIVATE = 32,
    // values
    INTV = 100,
    STRINGV = 101,
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
    COMMA,
    POINT,
    // composed symbols
    EQUAL = 250,
    IS_EQUAL,
    IS_EQUIVALENT,
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
    "any",
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
    "private"};

std::vector<std::string> symbols = {
    ";", "(", ")", "{", "}", "[", "]", "+",
    "-", ",", "."};

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

std::string toString(TokenType tokentype)
{
    if (tokentype < 100)
    {
        return keywords[tokentype];
    }
    switch (tokentype)
    {
    case SEMI:
        return "SEMICOLON";
    case INTV:
        return "INT_VALUE";
    case STRINGV:
        return "STRING_VALUE";
    case EQUAL:
        return "EQUAL";
    case IS_EQUAL:
        return "IS_EQUAL";
    case IS_EQUIVALENT:
        return "IS_EQUIVALENT";
    case PAR_OPEN:
        return "PAR_OPEN";
    case PAR_CLOSE:
        return "PAR_CLOSE";
    case CURLY_OPEN:
        return "CURLY_OPEN";
    case CURLY_CLOSE:
        return "CURLY_CLOSE";
    case PLUS:
        return "PLUS";
    case MINUS:
        return "MINUS";
    case COMMA:
        return "COMMA";
    case POINT:
        return "POINT";
    case IDENTIFIER:
        return "IDENTIFIER";
    default:
        return "Unknown token name";
    }
}