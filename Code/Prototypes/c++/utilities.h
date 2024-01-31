#pragma once

// Used for rng
#include <random>
#include <chrono>

// For making 2D vectors easier to read. These are all the columns
class Indices
{
// NOTE: I think I had a type error a while ago and needed "constexpr static int"
public:
    constexpr static const int TYPES = 0; 
    constexpr static const int NUMBERS = 1; 
    constexpr static const int BRACKETS = 2; 
    constexpr static const int KEYWORDS = 3; 
    constexpr static const int VARIABLES = 4; 
    constexpr static const int OPERATORS = 5; 
    constexpr static const int PUNCTUATION = 6; 
    constexpr static const int ACTOR_NAMES = 7; 
    constexpr static const int STATE_NAMES = 8;
    constexpr static const int VARIABLE_NAMES = 9;
    constexpr static const int EVENT_NAMES = 10;
    constexpr static const int STRING_INPUT = 11;
};

class Utilities
{ 
public:
    Utilities();
    int rand_between(const int&, const int&);
    ~Utilities();
};