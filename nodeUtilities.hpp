#pragma once
#include "tokenUtilities.hpp"
struct ExpressionNode
{
    Token intv;
};

struct ReturnNode
{
    ExpressionNode expr;
};