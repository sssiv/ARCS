#pragma once

#include "interface.h"

class NumberNode : public Interface
{
private:
    double value;
public:
    NumberNode();
    NumberNode(double);
    double evaluate() override;
    ~NumberNode();
};

