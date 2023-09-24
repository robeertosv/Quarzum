#include "Quarzum.h"
using namespace std;

int main(int argc, char *argv[])
{

    double exec_time{0.0};
    clock_t begin = clock();
    if (argc < 2)
    {
        cerr << "Error: Not enough arguments." << endl;
        return EXIT_FAILURE;
    }
    cout << "\nCompiling " << argv[1] << "...\n-------------------------\n\n";

    string source = getSource(argv[1]);

    compile(source);
    exit(EXIT_SUCCESS);
    return 0;
}