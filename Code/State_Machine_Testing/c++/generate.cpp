#include "generate.h"

Generate::Generate()
{
    Tokens* _Tokens = new Tokens;
    Variables* _Variables = new Variables;
    _tokens = _Tokens->getTokens();
    _variables = _Variables->getVariables();
    _code = "";

    delete _Tokens, _Variables;
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

void Generate::generateCode(const std::string& filename)
{
    // Create and open a text file
    std::ofstream MyFile(filename);

    // Writes code
    MyFile << _code;

    // Close the file
    MyFile.close();
}