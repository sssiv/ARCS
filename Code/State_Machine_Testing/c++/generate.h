#pragma once

#include "variables.h"
#include "events.h"

class Generate
{
private:
    Tokens _Tokens;
    Variables _Variables;
    Events _Events;
    std::vector<std::vector<std::string>> _tokens;

    std::string _code;

    std::vector<std::tuple<std::string, std::string, std::string>> _variables;
    int numOfVariables;

    int rand_between(const int&, const int&);
    
public:
    Generate();
    std::string generateVariables();
    
    std::string generateEvents();
    
    std::string generateActors();
    std::string generateStatemachine();
    std::string generateStates();

    // Generates a new text file with proteus code
    void generateCode(const std::string&);

    ~Generate(){};
};
