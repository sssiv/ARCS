#pragma once

// basic IO
#include <iostream>

// File handler libraries
#include <fstream>
#include <sstream>

// For vectors and vector compatiable functions 
#include <vector>
#include <algorithm>

// Token handler
class Tokens
{
private:
    // All proteus tokens
    std::vector<std::vector<std::string>> _tokens;

    // Data from CSV
    void readCSV();

    // Data from notepad generated from python token.py
    void read();

public:
    Tokens();
    inline const std::vector<std::vector<std::string>>& getTokens() const {return _tokens;};
    void printTokens();
    ~Tokens(){};
};
