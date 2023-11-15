#pragma once

#include "variables.h"
#include "events.h"

class Generate : public Utilities
{
private:
    Tokens _Tokens;
    Variables _Variables;
    Events _Events;
    
    std::string _code;
    std::vector<std::vector<std::string>> _tokens;
    std::vector<std::tuple<std::string, std::string, std::string>> _variables;
    std::vector<std::pair<std::string, std::string>> _events;
    
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
