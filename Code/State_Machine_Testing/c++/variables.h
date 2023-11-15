#pragma once

#include "tokens.h"
#include "utilities.h"
#include <utility>
#include <tuple>

class Variables : public Utilities
{
private:
    Tokens _Tokens;
    std::vector<std::vector<std::string>> _tokens;
    std::vector<std::tuple<std::string, std::string, std::string>> _variables;

    void makeNamesAndTypes();
    std::string makeValue(const std::string&);

public:
    Variables();
    void makeNewValues(std::vector<std::tuple<std::string, std::string, std::string>>&);
    void makeNewValue(const std::string&, std::vector<std::tuple<std::string, std::string, std::string>>&);
    const std::vector<std::tuple<std::string, std::string, std::string>>& getVariables() const {return _variables;};
    ~Variables();
};