#pragma once
#include "op.h"

// holds nodes
class ASTNode
{
public:
    ASTNode();
    Interface* number(double);
    Interface* intOperator(int, Interface*, Interface*);
    ~ASTNode();
};