#include "generate.h"

Generate::Generate()
{
};


int Generate::rand_between(const int& from, const int& to)
{
    // True Random
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

str Generate::generateEvents()
{
    return "";
}

str Generate::generateVariables()
{
    return "";
}

str Generate::generateActors()
{
    return "";
}

str Generate::generateStatemachine()
{
    return "";
}

str Generate::generateStates()
{
    return "";
}

void Generate::generateCode(const str& filename)
{
    // Create and open a text file
    std::ofstream MyFile(filename);
    // MyFile << _code;
    // Close the file
    MyFile.close();
}