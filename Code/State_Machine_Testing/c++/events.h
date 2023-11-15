#pragma once

#include "tokens.h"
#include "functions.h"

class Events : public Functions
{
private:
    Tokens _Tokens;
    std::vector<std::vector<std::string>> _tokens;
    std::vector<std::pair<std::string, std::string>> _events;
public:
    Events();
    ~Events();
};