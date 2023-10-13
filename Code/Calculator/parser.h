#pragma once

#include "token.h"

class Parser
{
private:
    Token _currentToken;
    Tokenizer _tokenizer;

    double expression();
    double term();
    double factor();

    void nextToken();
    
public:
    Parser(Tokenizer&);
    double parse();
};
