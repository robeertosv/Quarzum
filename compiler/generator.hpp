#pragma once

class Generator
{
public:
    Generator(Exit stat) : m_stat(move(stat)) {}
    string generate()
    {
        /* Generates assembly code from the values of the AST */
        string assembly;
        assembly += "   global _main\n  section '.text'\n_main:\n";
        assembly += "   MOV rax, 60\n";
        assembly += "   MOV rdi, " + m_stat.value.literal.value + "\n";
        assembly += "   syscall";
        return assembly;
    }

private:
    Exit m_stat;
};