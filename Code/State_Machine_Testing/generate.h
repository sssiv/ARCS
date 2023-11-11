#pragma once
#include "tokens.h"
#include <tuple>

class Generate
{
private:
// Generates a random number starting "From" X all the way "to" Y
    int rand_between(const int&, const int&);
    std::tuple<std::string, std::string, std::string> generateVariableValue(const std::string&, const std::string&);

    std::string _code;
    Tokens _Tokens;
    std::vector<std::vector<std::string>> _tokens;
    std::vector<std::pair<std::string, std::string>> _events;
    std::vector<std::tuple<std::string, std::string, std::string>> _variables;
    
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
