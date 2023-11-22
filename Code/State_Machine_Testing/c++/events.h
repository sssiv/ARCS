#pragma once

#include "tokens.h"
#include "utilities.h"

class Events : public Utilities
{
private:
    // Tokens to obtain events data
    Tokens _Tokens;

    // Store data
    std::vector<std::vector<std::string>> _tokens;
    std::vector<std::pair<std::string, std::string>> _events;

    void makeNamesAndTypes();
    
public:
    Events();
    const std::vector<std::pair<std::string, std::string>>& getEvents() const {return _events;};
    ~Events();
};