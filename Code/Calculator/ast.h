#pragma once
#include "op.h"

// expression, factor, term Node
class ASTNode
{
public:
    ASTNode();
    Interface* number(double);
    Interface* intOperator(char, Interface*, Interface*);
    ~ASTNode();
};
