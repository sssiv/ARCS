#include "generate.h"

Generate::Generate()
{
    _tokens = _Tokens.getTokens();
    _variables = _Variables.getVariables();
    _code = "";
};

// True Random
int Generate::rand_between(const int& from, const int& to)
{
    // Set Seed
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);

    // Uniform Distribution RNG
    std::uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

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
    for (const auto& variable : _variables)
    {
        std::cout << std::get<0>(variable) << ", " << std::get<1>(variable) << ", " << std::get<2>(variable) + "\n";
    }
    // Close the file
    MyFile.close();
}