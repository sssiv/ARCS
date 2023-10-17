#pragma once

#include "op.h"

// List of all tokens
enum class Tokens 
{
    NUMBER, PLUS, MINUS, MULTIPLY, DIVIDE, 
    LPARTH, RPARTH, STOP
};

// Current Token Holder
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
    const std::string& _expression;     // The overall input expression
    size_t _currentPos;                 // Counter as we itr through the expression

public:
    Tokenizer(const std::string&);      // A Parser object will take in the token class with the expression
    Token getNextToken();               // This itr's through each token as we evaluate the expression
};