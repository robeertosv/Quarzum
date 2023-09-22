#pragma once

class Generator
{
public:
    Generator(ExitStatement stat) : m_stat(move(stat)) {}
    string generate()
    {
        string assembly;
        assembly += "global _start\n_start:\n";
        assembly += "   mov rax, 60\n";
        assembly += "   mov rdi, " + m_stat.value.literal.value + "\n";
        assembly += "   syscall";
        return assembly;
    }

private:
    ExitStatement m_stat;
};