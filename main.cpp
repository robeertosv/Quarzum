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
    compile(source);
    exit(EXIT_SUCCESS);
    return 0;
}