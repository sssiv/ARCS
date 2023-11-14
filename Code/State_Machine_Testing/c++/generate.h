#pragma once
#include "tokens.h"

class Generate
{
private:
// Generates a random number starting "From" X all the way "to" Y
    int rand_between(const int&, const int&);
    
public:
    Generate();
 
    str generateEvents();
    str generateVariables();
    str generateActors();
    str generateStatemachine();
    str generateStates();

    // Generates a new text file with proteus code
    void generateCode(const str&);

    ~Generate(){};
};
