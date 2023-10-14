#pragma once

#include "op.h"

// Token list
enum class Tokens {NUMBER, PLUS, MINUS, LPARTH, RPARTH, STOP};

// Token Holder
struct Token
{
    Tokens token;   // Current Token
    double value;   // Tokens Value

    Token();
    Token(Tokens, double);  // Takes in Tokens/enum and its value
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