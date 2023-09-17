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
        result += "global _start\n_start:\n     mov rax, 60\n     mov rdi, 100\n     syscall";
        cout
            << "Generating procedure finished." << endl;
        return result;
    }

private:
    SyntaxTree nodes;
};