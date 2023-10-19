#pragma once

#include "interface.h"

class NumberNode : public Interface
{
private:
    double value;
public:
    NumberNode();
    NumberNode(const double&);
    double evaluate() override;
    ~NumberNode();
};