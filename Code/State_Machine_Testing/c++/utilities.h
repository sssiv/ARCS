#pragma once

// Used for rng
#include <random>
#include <chrono>

// For making 2D vectors easier to read. These are all the columns
class Indices
{
public:
    constexpr static int TYPES = 0; 
    constexpr static int NUMBERS = 1; 
    constexpr static int BRACKETS = 2; 
    constexpr static int KEYWORDS = 3; 
    constexpr static int VARIABLES = 4; 
    constexpr static int OPERATORS = 5; 
    constexpr static int PUNCTUATION = 6; 
    constexpr static int ACTOR_NAMES = 7; 
    constexpr static int STATE_NAMES = 8;
    constexpr static int VARIABLE_NAMES = 9;
    constexpr static int EVENT_NAMES = 10;
    constexpr static int STRING_INPUT = 11;
};

class Utilities
{ 
public:
    Utilities();
    int rand_between(const int&, const int&);
    ~Utilities();
};