#include "ast.h"

ASTNode::ASTNode() {}

Interface *ASTNode::newNumber(const double& value)
{
    return new NumberNode(value);
}

Interface *ASTNode::intOperator(const int& op, Interface* left, Interface* right)
{
    return new OperatorNode(op, left, right);
}

ASTNode::~ASTNode() {}