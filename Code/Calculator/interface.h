#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Interface
{
public:
    Interface();
    virtual double evaluate() = 0;
    ~Interface();
};