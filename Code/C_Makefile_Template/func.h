#ifndef FYNC_H_
#define FUNC_H_

#include <iostream>
#include <random>
#include <chrono>

class Func
{
private:
    double isTrue(double);
    bool boolValue(double);
    int random(int, int, int);
public:
    Func();
    ~Func();
    void Print();
};


#endif // FUNC_H_