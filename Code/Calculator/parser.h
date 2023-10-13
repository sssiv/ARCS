#pragma once

#include "token.h"


class Parser
{
private:
    Token _currentToken;    // Holds current token
    Tokenizer _tokenizer;   // Used to get next token and send input

    double expression();    // expression  ::= term   | {"+" | "-"} term
    double term();          // term        ::= factor | {"+" | "-"} factor
    double factor();        // factor      ::= Number | "(" expression "")"

    void nextToken();       // Initializes current token to the next
    
public:
    Parser(Tokenizer&);
    double parse();         // Runs program
};
