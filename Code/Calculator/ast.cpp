#include "ast.h"

ASTNode::ASTNode() 
{
}

Interface *ASTNode::number(double value)
{
    return new NumberNode(value);
}

Interface *ASTNode::intOperator(char op, Interface* left, Interface* right)
{
    return new OperatorNode(op, left, right);
}

ASTNode::~ASTNode() 
{   
}