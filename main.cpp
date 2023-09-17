#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "tokenUtilities.hpp"
#include "nodeUtilities.hpp"
#include "splitter.hpp"
#include "composer.hpp"
#include "parser.hpp"

using namespace std;
string getSource(string path)
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
    for (int i = 0; i < composed.size(); i++)
    {
        cout << composed.at(i).type;
        cout << " | ";
        cout << composed.at(i).value.value() << endl;
    }
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Error: Not enough arguments." << endl;
        return EXIT_FAILURE;
    }

    cout << "Compiling " << argv[1] << "..." << endl
         << "------------" << endl;

    string source = getSource(argv[1]);

    Splitter splitter(source);
    vector<Token> tokens = splitter.split();

    Composer composer(tokens);
    vector<Token> composed = composer.compose();

    // debug(composed);
    Parser parser(composed);
    optional<ReturnNode> node = parser.parse();

    cout << "Operation finished. Success!" << endl
         << endl;
    return EXIT_SUCCESS;
}