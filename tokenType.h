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
    // values
    INTV = 100,
    // symbols
    SEMI = 200,
    EQUAL,
    IS_EQUAL,
    IS_EQUIVALENT,
    PAR_OPEN,
    PAR_CLOSE,
    CURLY_OPEN,
    CURLY_CLOSE,
    SQUARE_OPEN,
    SQUARE_CLOSE,
    PLUS,
    MINUS,
    COMMA,
    // others
    IDENTIFIER = 300
};

std::string toString(TokenType tokentype)
{
    switch (tokentype)
    {
    case RETURN:
        return "RETURN";
    case INT:
        return "INT";
    case NUMBER:
        return "NUMBER";
    case STRING:
        return "STRING";
    case BOOL:
        return "BOOL";
    case ANY:
        return "ANY";
    case FUNCTION:
        return "FUNCTION";
    case CONST:
        return "CONST";
    case UNDEFINED:
        return "UNDEFINED";
    case SEMI:
        return "SEMICOLON";
    case INTV:
        return "INT_VALUE";
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
    case PLUS:
        return "PLUS";
    case MINUS:
        return "MINUS";
    case COMMA:
        return "COMMA";
    case IDENTIFIER:
        return "IDENTIFIER";
    default:
        return "Unknown token name";
    }
}

std::string keywords[9] = {
    "return",
    "int",
    "number",
    "string",
    "bool",
    "any",
    "function",
    "const",
    "undefined"};