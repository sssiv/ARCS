#pragma once

#include "number.h"

class OperatorNode : public ASTNode
{
private:
    char op;
    ASTNode* left;
    ASTNode* right;

public:
    OperatorNode(char, ASTNode*, ASTNode* );
    double evaluate() override;
};