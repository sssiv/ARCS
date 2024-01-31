#include "func.h"

int Func::random(int itr, int r1, int r2)
{
    // Needs random and chrono
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(r1, r2);
    for (int i = 0; i < itr; ++i) 
        std::cout <<  dist(gen) << " ";
    return 0;
}

Func::Func()
{
}

Func::~Func()
{
}

void Func::Print()
{
    random(15, 0, 100);
}