#pragma once

//#include "token.h"
#include "ast.h"

class Parser
{
private:
    Tokenizer* _tokenizer;   // Used to get next token and send input
    ASTNode* AST;
    
public:
    // Does this constructor need to be 'explicit' ?
    Parser(Tokenizer*);
    Interface* parse();   // Runs parser
    ~Parser();
};