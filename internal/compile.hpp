void compile(string source)
{
    Lexer lexer = Lexer(source);
    deque<Token> tokens = lexer.tokenize();
    debug(tokens);
}