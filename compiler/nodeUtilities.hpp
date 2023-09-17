#pragma once
#include "tokenUtilities.hpp"
#include <vector>
#include <variant>
using namespace std;

struct OperatorNode
{
    Token token;
};

struct ExpressionNode
{
    Token token;
};

struct ReturnNode
{
    ExpressionNode expr;
};

struct ExitNode
{
    ExpressionNode exitCode;
};
struct IntAssignment
{
    Token identifier;
    Token value;
};
// Basic node that contains instructions by itself
struct StatementNode
{
    IntAssignment statement;
};

// Modules contains the same as Syntax Tree, but only an exportable portion
struct ModuleNode
{
    vector<ExitNode> exitNodes;
};

// Universal container, contains every node
struct SyntaxTree
{
    vector<StatementNode> nodes;
};