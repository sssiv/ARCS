#pragma once

#include "token.h"

class Parser
{
private:
    Token _currentToken;    // Holds current token
    Tokenizer _tokenizer;   // Used to get next token and send input

    ASTNode* AST;
    
    Interface* expression();    // expression  ::= term   | {"+" | "-" | "*" | "/"} term
    Interface* term();          // term        ::= factor | {"+" | "-" | "*" | "/"} factor
    Interface* factor();        // factor      ::= Number | "(" expression "")"

    void nextToken();       // Initializes current token to the next
    
public:
    Parser(Tokenizer&);
    //double parse();         // Runs program
    Interface* parse();   // Runs program
};