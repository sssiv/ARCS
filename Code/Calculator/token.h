#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>

// Token list
enum class Tokens {NUMBER, PLUS, MINUS, LPARTH, RPARTH, STOP};

// Token Holder
struct Token
{
    Tokens token;
    double value;

    Token();
    Token(Tokens, double);
};

// Holds the input expression
// Gives each token when needed
class Tokenizer
{
private:
    const std::string& _expression;
    size_t _currentPos;

public:
    Tokenizer(const std::string&);
    Token getNextToken();
};