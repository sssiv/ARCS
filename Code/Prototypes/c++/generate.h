#pragma once

// Utilities already included from the following headers
#include "utilities.h"
#include "tokens.h"

class Generate : public Utilities
{
private:

    // String to write final code 
    std::string _code;

    // Access Tokens
    Tokens _Tokens;
    
public:
    Generate();
    void generateRandomTokens(const std::string&);
    ~Generate(){};
};