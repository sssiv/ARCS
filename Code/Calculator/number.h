#pragma once

#include "ast.h"

class NumberNode : public ASTNode
{
private:
    double value;
public:
    NumberNode();
    NumberNode(double);
    double evaluate();
    ~NumberNode();
};

