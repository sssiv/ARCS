#pragma once

#include "tokens.h"
#include "utilities.h"

class Events : public Utilities
{
private:
    Tokens _Tokens;
    std::vector<std::vector<std::string>> _tokens;
    std::vector<std::pair<std::string, std::string>> _events;
public:
    Events();
    ~Events();
};