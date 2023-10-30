#pragma once

#include "interface.h"
#include <cmath>

// Operator stored as a pointer node
class OperatorNode : public Interface
{
private:
    int op;
    Interface* left;
    Interface* right;

public:
    OperatorNode();

    // Takes in Operator ID, lhs variable, rhs variable
    OperatorNode(const int&, Interface*, Interface*);

    // executes operation
    double evaluate() override;
    ~OperatorNode();
};