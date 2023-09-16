enum TokenType
{
    // keywords
    RETURN = 0,
    INT,
    NUMBER,
    STRING,
    BOOL,
    ANY,
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
    COMMA,
    POINT,
    LESS,
    GREATER,
    // composed symbols
    EQUAL = 250,
    IS_EQUAL,
    IS_EQUIVALENT,
    PLUS_UNARY,
    MINUS_UNARY,
    PLUS_EQUAL,
    MINUS_EQUAL,
    LESS_EQUAL,
    GREATER_EQUAL,
    // others
    IDENTIFIER = 300,
    NONE = 301
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
    "-", ",", ".", "<", ">"};

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
    case NUMBERV:
        return "NUMBER_VALUE";
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
    case PLUS_UNARY:
        return "PLUS_UNARY";
    case MINUS_UNARY:
        return "MINUS_UNARY";
    case PLUS_EQUAL:
        return "PLUS_EQUAL";
    case MINUS_EQUAL:
        return "MINUS_EQUAL";
    case LESS_EQUAL:
        return "LESS_EQUAL";
    case GREATER_EQUAL:
        return "GREATER_EQUAL";
    case COMMA:
        return "COMMA";
    case POINT:
        return "POINT";
    case IDENTIFIER:
        return "IDENTIFIER";
    case NONE:
        break;
    default:
        return "Unknown token name";
    }
}