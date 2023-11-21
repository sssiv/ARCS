#pragma once

// Utilities already included from the following headers
#include "variables.h"
#include "events.h"


class Generate : public Utilities
{
private:
    // Code content objects
    Tokens _Tokens;
    Variables _Variables;
    Events _Events;
    
    // String to write final code 
    std::string _code;

    // Store data
    std::vector<std::vector<std::string>> _tokens;
    std::vector<std::tuple<std::string, std::string, std::string>> _variables;
    std::vector<std::pair<std::string, std::string>> _events;
    
public:
    Generate();
    std::string generateEvents();
    std::string generateVariables();
    
    std::string generateActors();
    std::string generateStatemachine();
    std::string generateStates();

    // Generates a new text file with proteus code
    void generateCode(const std::string&);

    void generateRandomTokens(const std::string&);

    ~Generate(){};
};
