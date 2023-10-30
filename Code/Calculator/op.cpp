#include "op.h"

OperatorNode::OperatorNode()
{
}

// Takes in Operator ID, lhs variable, rhs variable
OperatorNode::OperatorNode(const int& op, Interface* left, Interface* right) : op(op), left(left), right(right) {}

double OperatorNode::evaluate()
{
    // add
    if (op == 1) return left->evaluate() + right->evaluate();

    // subtract
    else if (op == 2) return left->evaluate() - right->evaluate();

    // multiply
    else if (op == 3) return left->evaluate() * right->evaluate();

    // divide
    else if (op == 4)
    {
        // check for division by 0
        if (right->evaluate() == 0)
        {
            return std::nan("");
        }
        else
            return left->evaluate() / right->evaluate();
    } 
    return 0.0;  
}

OperatorNode::~OperatorNode()
{
}