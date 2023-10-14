#pragma once

#include <iostream>
#include <string>
#include <cmath>

// expression, factor, term Node
class ASTNode
{
public:
    ASTNode();
    virtual double evaluate() = 0;
    ~ASTNode();
};
