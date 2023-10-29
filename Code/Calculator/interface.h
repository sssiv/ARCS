#pragma once

class Interface
{
public:
    Interface();
    virtual double evaluate() = 0;
    ~Interface();
};