#include "op.h"

OperatorNode::OperatorNode(char op, ASTNode* left, ASTNode* right) : op(op), left(left), right(right) {}

double OperatorNode::evaluate()
{
    if (op == '+')
        return left->evaluate() + right->evaluate();
    else if (op == '-')
        return left->evaluate() - right->evaluate();
    else if (op == '*')
        return left->evaluate() * right->evaluate();
    else if (op == '/')
    {
        if (right->evaluate() == 0)
            std::cerr <<  "Error: Cannot divide by 0\n";
        else
            return left->evaluate() / right->evaluate();
    }   
}
