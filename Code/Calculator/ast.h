#pragma once

#include "token.h"
#include "op.h"
#include "number.h"
//#include "interface"
//#include <iostream>

// Collects tokens, returns instances 
class ASTNode
{
private:
    Token* _currentToken;    // Holds current token
    Tokenizer* _tokenizer;   // Used to get next token and send input
    
public:
    ASTNode();

    // Number Node
    Interface* newNumber(const double&);
    // Operator Node
    Interface* intOperator(const int&, Interface*, Interface*);

    // expression  ::= term   | Operator term
    Interface* expression();    
    // term        ::= factor | Operator factor               
    Interface* term();   
    // factor      ::= Number | "(" expression* "")"                       
    Interface* factor(); 
    // Operator    ::= {"+" | "-" | "*" | "/"}                       
    Interface* ops(Interface*, const int&);     

    // collect tokens to pass to _Tokenizer
    void getTokens(Tokenizer*);

    // Initializes current token to the next
    inline void nextToken() { _currentToken = _tokenizer->getNextToken();};  

    // Checks if we reached the end of the expression     
    bool stopCheck();
    ~ASTNode();
};