enum TokenType
{
    // keywords
    RETURN,
    INT,
    // values
    INTV,
    // symbols
    SEMI,
    EQUAL,
    IS_EQUAL,
    IS_EQUIVALENT,
    // others
    IDENTIFIER
};

std::string toString(TokenType tokentype)
{
    switch (tokentype)
    {
    case RETURN:
        return "RETURN";
    case INT:
        return "INT";
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
    case IDENTIFIER:
        return "IDENTIFIER";
    default:
        return "Unknown token name";
    }
}