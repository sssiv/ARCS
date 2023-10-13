#include "parser.h"

Parser::Parser(Tokenizer& T) : _tokenizer(T) {}

double Parser::expression()
{
    return 0.0;
}

double Parser::term()
{
    return 0.0;
}

double Parser::factor()
{
    return 0.0;
}

// advance to the next token
void Parser::nextToken() {_currentToken = _tokenizer.getNextToken();}

double Parser::parse()
{
    return 0.0;
}
