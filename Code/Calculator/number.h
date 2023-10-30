#pragma once

#include "interface.h"

// Double value stored as a pointer node
class NumberNode : public Interface
{
private:
    double value;

public:
    NumberNode();

    // Take in a numerical value, becomes a number
    NumberNode(const double&);
    double evaluate() override;
    ~NumberNode();
};