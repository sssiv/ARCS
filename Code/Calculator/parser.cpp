#include "parser.h"

// When we take in a tokenizer class,
// we have the input expression in a string
// and we control the index variable where 
// we are currently looking in the expression
Parser::Parser(Tokenizer* tokenizer) 
{
    AST = new ASTNode;
    AST->getTokens(tokenizer);
    AST->nextToken();
}

// Starts the parsing
Interface* Parser::parse()
{
    Interface* result = AST->expression();
    if (!AST->stopCheck())
    {
        std::cerr << "Error: Parser did not reach the end of the expression.\n";
        delete result;
        return nullptr;
    }
    return result;
}

Parser::~Parser() {delete AST;}