#include "op.h"

OperatorNode::OperatorNode(char op, Interface* left, Interface* right) : op(op), left(left), right(right) {}

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
        {
            std::cerr <<  "Error: Cannot divide by 0\n";
            return std::nan("");
        }
        else
            return left->evaluate() / right->evaluate();
    }   
}
