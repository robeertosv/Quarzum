#include "Quarzum.h"

using namespace std;
/*

    Minified main.cpp, all the procedures are into Quarzum.h

*/
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        throwError(0);
    }
    string source = getSource(argv[1]);

    /* Compiles the source code step by step */
    Lexer lexer = Lexer(source);
    deque<Token> tokens = lexer.tokenize();
    debug(tokens);

    // Parser parser = Parser(tokens);
    // Root exit = parser.parse();

    // Generator generator = Generator(exit.childs.at(0));
    // string assembly = generator.generate();

    // cout << assembly << endl;

    // fstream file("out.asm", ios::out);
    // file << assembly;
    return 0;
}