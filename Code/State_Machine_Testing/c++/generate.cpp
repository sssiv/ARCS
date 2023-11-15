#include "generate.h"

Generate::Generate()
{
    // Get all code data
    _tokens = _Tokens.getTokens();
    _variables = _Variables.getVariables();
    _events = _Events.getEvents();

    // Empty string to write code
    _code = "";
};

std::string Generate::generateEvents()
{
    // Empty string to write events
    std::string code = "";

    code += "Events: \n";

    // Write events
    for (const auto& event : _events)
    {
        code += event.first + ", " + event.second + "\n";
    }
    code += "\n";

    // Return events
    return code;
}

std::string Generate::generateVariables()
{
    // Empty string to write variables
    std::string code = "";

    code += "Variables: \n";

    // Write Variables
    for (const auto& variable : _variables)
    {
        code += std::get<0>(variable) + ", " + std::get<1>(variable) + ", " + std::get<2>(variable) + "\n";
    }
    code += "\n";

    // Return variables
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
void Generate::generateCode(const std::string& file)
{
    // Create and open a text file
    std::ofstream MyFile(file);

    // Generate events first
    _code += generateEvents();

    // Actor

    // Variables
    _code += generateVariables();

    //States
    
    // Writes code
    MyFile << _code;

    // Close the file
    MyFile.close();
}