#pragma once

//#include "op.h"
#include "token.h"

// holds nodes
class ASTNode
{
private:
    Token* _currentToken;    // Holds current token
    Tokenizer* _tokenizer;   // Used to get next token and send input
    
public:
    ASTNode();
    Interface* newNumber(const double&);
    Interface* intOperator(const int&, Interface*, Interface*);

    Interface* expression();                    // expression  ::= term   | Operator term
    Interface* term();                          // term        ::= factor | Operator factor
    Interface* factor();                        // factor      ::= Number | "(" expression* "")"
    Interface* ops(Interface*, const int&);     // Operator    ::= {"+" | "-" | "*" | "/"}

    void getTokens(Tokenizer*);
    void nextToken();       // Initializes current token to the next
    bool stopCheck();
    ~ASTNode();
};