void compile(string src)
{
    /* Compiles the source code step by step */
    Lexer lexer = Lexer(src);
    deque<Token> tokens = lexer.tokenize();

    Parser parser = Parser(tokens);
    Root exit = parser.parse();

    Generator generator = Generator(exit.childs.at(0));
    string assembly = generator.generate();

    cout << assembly << endl;

    fstream file("out.asm", ios::out);
    file << assembly;
}