#pragma once

#include "number.h"

class OperatorNode : public Interface
{
private:
    char op;
    Interface* left;
    Interface* right;

public:
    OperatorNode(int, Interface*, Interface*);
    double evaluate() override;
};