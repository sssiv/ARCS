#pragma once
#include "op.h"

// holds nodes
class ASTNode
{
public:
    ASTNode();
    Interface* newNumber(const double&);
    Interface* intOperator(const int&, Interface*, Interface*);
    ~ASTNode();
};