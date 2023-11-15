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
    std::string code = "";

    // Writes events to txt
    code += "Events: \n";
    for (const auto& event : _events)
    {
        code += event.first + ", " + event.second + "\n";
    }
    code += "\n";
    return code;
}

std::string Generate::generateVariables()
{
    std::string code = "";

    // Writes variables to txt
    code += "Variables: \n";
    for (const auto& variable : _variables)
    {
        code += std::get<0>(variable) + ", " + std::get<1>(variable) + ", " + std::get<2>(variable) + "\n";
    }
    code += "\n";
    return code;
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

    _code += generateVariables();
    _code += generateEvents();
    
    // Writes code
    MyFile << _code;

    // Close the file
    MyFile.close();
}