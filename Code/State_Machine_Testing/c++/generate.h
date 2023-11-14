#pragma once
#include "tokens.h"

class Generate
{
private:
    Tokens _Tokens;

    std::vector<std::vector<std::string>> _tokens;

    int rand_between(const int&, const int&);
    
public:
    Generate();
 
    std::string generateEvents();
    std::string generateVariables();
    std::string generateActors();
    std::string generateStatemachine();
    std::string generateStates();

    // Generates a new text file with proteus code
    void generateCode(const std::string&);

    ~Generate(){};
};
