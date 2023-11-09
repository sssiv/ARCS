#include <iostream>
#include <random>
#include <chrono>

using namespace std;

// Generates a random number starting "From" X all the way "to" Y
int rand_between(const int& from, const int& to)
{
    // True Random
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

int main()
{
    cout << "Hello" << endl;
}