#pragma once

#include "ast.h"
//#include "token.h"

// Executes the expression
// Tokenizer is used to get the tokens
// AST is used to execute in the parser
class Parser
{
private:
    Tokenizer* _tokenizer;   // Used to get next token and send input
    ASTNode* AST;
    
public:
    // Takes in expression and tokenizes 
    Parser(Tokenizer*);
    
    // Runs parser
    Interface* parse();   
    ~Parser();
};