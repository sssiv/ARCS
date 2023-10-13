#pragma once
#include <random>
#include "../src/LockState.h"

int generateRandomNumber(int, int);

struct Data
{
    int numOfTests;
    int pass = 0;
    int fail = 0;
};

// test internals
class Whitebox
{
private:
    Data data;
public:
    Whitebox();
    int successes();
    int failures();
    LockState::State testState();
};

/*********************************************************************************/

// Input expect output
class Blackbox : public Whitebox
{
private:
    Data data;
public:
    Blackbox();
    void manual();
    
};