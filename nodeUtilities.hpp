#pragma once
#include "tokenUtilities.hpp"
#include <vector>
using namespace std;
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

struct SyntaxTree
{
    vector<ExitNode> exitNodes;
};