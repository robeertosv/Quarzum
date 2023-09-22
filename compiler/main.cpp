#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <optional>
#include <stdio.h>
#include <time.h>
#include <cstring>

#include "utilities.hpp"
#include "lexer.hpp"

using namespace std;
string getSource(const string path)
{
    ifstream input(path);
    string source, line;
    while (getline(input, line))
    {
        source += line + '\n';
    }
    return source;
}
void debug(deque<Token> composed)
{
    for (unsigned short int i = 0; i < composed.size(); i++)
    {
        cout << composed.at(i).type;
        cout << " | ";
        cout << composed.at(i).value << endl;
    }
}
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

    deque<Token> tokens = tokenize(source);
    debug(tokens);
    clock_t split_t = clock();
    cout << "Split phase finished in " << (double)(split_t - begin) / CLOCKS_PER_SEC << " seconds.\n";

    return EXIT_SUCCESS;
}