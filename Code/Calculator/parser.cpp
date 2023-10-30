#include "parser.h"

// When we take in a tokenizer class,
// we have the input expression in a string
// and we control the index variable where 
// we are currently looking in the expression
Parser::Parser(Tokenizer* tokenizer) 
{
    AST = new ASTNode;          // get fresh AST
    AST->getTokens(tokenizer);  // collect the input and tokenize
    AST->nextToken();           // start at the first token
}

// Runs parser
Interface* Parser::parse()
{
    // In the grammar, expression starts everything off
    // and works it way using the Top-Down Recursive approach
    Interface* result = AST->expression();
    if (!AST->stopCheck())
    {
        std::cerr << "Error: Parser did not reach the end of the expression.\n";
        delete result;
        return nullptr;
    }
    return result;
}

// Clear memory, AST
Parser::~Parser() {delete AST;}