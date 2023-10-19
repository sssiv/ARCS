#pragma once

#include "token.h"
//#include "ast.h"

class Parser
{
private:
    Token* _currentToken;    // Holds current token
    Tokenizer* _tokenizer;   // Used to get next token and send input

    ASTNode* AST;
    
    Interface* expression();                    // expression  ::= term   | Operators term
    Interface* term();                          // term        ::= factor | Operators factor
    Interface* factor();                        // factor      ::= Number | "(" expression "")"
    Interface* ops(Interface*, const int&);     // Operators   ::= {"+" | "-" | "*" | "/"}

    void nextToken();       // Initializes current token to the next
    
public:
    Parser(Tokenizer*);
    Interface* parse();   // Runs parser
};