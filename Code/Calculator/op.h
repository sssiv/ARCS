#pragma once

#include "interface.h"
#include <cmath>

class OperatorNode : public Interface
{
private:
    char op;
    Interface* left;
    Interface* right;

public:
    OperatorNode();
    OperatorNode(const int&, Interface*, Interface*);
    double evaluate() override;
    ~OperatorNode();
};