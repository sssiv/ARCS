#pragma once
#include "tokens.h"
#include <tuple>

#define _tuple_(i, j, k) std::tuple<i, j, k>
#define _pair_(i, j) std::pair<i, j>

class Generate
{
private:
// Generates a random number starting "From" X all the way "to" Y
    int rand_between(const int&, const int&);
    _tuple_(str, str, str) generateVariableValue(const str&, const str&);

    str _code;
    Tokens _Tokens;
    std::vector<std::vector<str>> _tokens;
    std::vector<_pair_(str, str)> _events;
    std::vector<_tuple_(str, str, str)> _variables;
    
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
