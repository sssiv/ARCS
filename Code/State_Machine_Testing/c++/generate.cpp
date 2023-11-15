#include "generate.h"

Generate::Generate()
{
    _tokens = _Tokens.getTokens();
    _variables = _Variables.getVariables();
    _events = _Events.getEvents();
    _code = "";
};

std::string Generate::generateEvents()
{
    return "";
}

std::string Generate::generateVariables()
{
    return "";
}

std::string Generate::generateActors()
{
    return "";
}

std::string Generate::generateStatemachine()
{
    return "";
}

std::string Generate::generateStates()
{
    return "";
}

// Makes complete proteus code
void Generate::generateCode(const std::string& filename)
{
    // Create and open a text file
    std::ofstream MyFile(filename);

    // Loop through each tuple in _variables and cout its elements
    for (const auto& variable : _variables)
    {
        _code += std::get<0>(variable) + ", " + std::get<1>(variable) + ", " + std::get<2>(variable) + "\n";
    }

    // Writes code
    MyFile << _code;

    // Close the file
    MyFile.close();
}