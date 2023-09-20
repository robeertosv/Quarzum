#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <stdio.h>
#include <time.h>
#include <cstring>

#include "tokenUtilities.hpp"
#include "nodeUtilities.hpp"
#include "splitter.hpp"
#include "composer.hpp"
#include "parser.hpp"
#include "generator.hpp"

using namespace std;
string getSource(const string path)
{
    ifstream input(path);
    string source;
    string line;
    while (getline(input, line))
    {
        source += line + "\n";
    }
    return source;
}
void debug(vector<Token> composed)
{
    for (unsigned short int i = 0; i < composed.size(); i++)
    {
        cout << composed.at(i).type;
        cout << " | ";
        cout << composed.at(i).value.value() << endl;
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

    Splitter splitter(source);
    vector<Token> tokens = splitter.split();
    clock_t split_t = clock();
    cout << "Split phase finished in " << (double)(split_t - begin) / CLOCKS_PER_SEC << " seconds.\n";

    Composer composer(tokens);
    vector<Token> composed = composer.compose();
    clock_t compose_t = clock();
    cout << "\nCompose phase finished in " << (double)(compose_t - begin) / CLOCKS_PER_SEC << " seconds.\n\n";

    clock_t end = clock();
    exec_time += (double)(end - begin) / CLOCKS_PER_SEC;

    Parser parser(composed);
    SyntaxTree nodes = parser.parse();

    // Generator generator(nodes);
    // string assembly = generator.generate();

    cout << "Operation finished in " << exec_time << " seconds. Success!\n\n";

    // cout << assembly;
    return EXIT_SUCCESS;
}