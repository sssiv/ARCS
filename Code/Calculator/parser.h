#pragma once

#include "token.h"

class Parser
{
private:
    Token _currentToken;    // Holds current token
    Tokenizer _tokenizer;   // Used to get next token and send input

    ASTNode* expression();    // expression  ::= term   | {"+" | "-"} term
    ASTNode* term();          // term        ::= factor | {"+" | "-"} factor
    ASTNode* factor();        // factor      ::= Number | "(" expression "")"

    void nextToken();       // Initializes current token to the next
    
public:
    Parser(Tokenizer&);
    //double parse();         // Runs program
    ASTNode* parse();   // Runs program
};