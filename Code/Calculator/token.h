#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>

enum class Tokens {NUMBER, PLUS, MINUS, LPARTH, RPARTH, STOP};

struct Token
{
    Tokens token;
    double value;

    Token();
    Token(Tokens, double);
};

class Tokenizer
{
private:
    const std::string& _expression;
    size_t _currentPos;

public:
    Tokenizer(const std::string&);
    Token getNextToken();
};