#pragma once
#include "nodeUtilities.hpp"
using namespace std;

class Generator
{
public:
    inline explicit Generator(SyntaxTree tree)
    {
        nodes = tree;
    }
    string generate()
    {
        string result;
        cout << "Generating procedure finished." << endl;
        return "";
    }

private:
    SyntaxTree nodes;
};