#include "utilities.h"

Utilities::Utilities()
{
}

int Utilities::rand_between(const int& from, const int& to)
{
    // Set Seed
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);

    // Uniform Distribution RNG
    std::uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

Utilities::~Utilities()
{
}