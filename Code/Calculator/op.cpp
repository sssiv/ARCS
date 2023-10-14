#include "op.h"

OperatorNode::OperatorNode(char op, ASTNode* left, ASTNode* right) : op(op), left(left), right(right) {}

double OperatorNode::evaluate()
{
    if (op == '+')
        return left->evaluate() + right->evaluate();
    if (op == '-')
        return left->evaluate() - right->evaluate();
}
