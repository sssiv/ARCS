#include "op.h"

OperatorNode::OperatorNode()
{
}

OperatorNode::OperatorNode(const int& op, Interface* left, Interface* right) : op(op), left(left), right(right) {}

double OperatorNode::evaluate()
{
    if (op == 1) return left->evaluate() + right->evaluate();
    else if (op == 2) return left->evaluate() - right->evaluate();
    else if (op == 3) return left->evaluate() * right->evaluate();
    else if (op == 4)
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

OperatorNode::~OperatorNode()
{
}