#pragma once

#include "token.h"

/*
expression  ::= term   | {"+" | "-"} term
term        ::= factor | {"+" | "-"} factor
factor      ::= Number | "(" expression "")"
*/

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
