#include "parser.h"

// When we take in a tokenizer class,
// we have the input expression in a string
// and we control the index variable where 
// we are currently looking in the expression
Parser::Parser(Tokenizer& tokenizer) : _tokenizer(tokenizer) {}

// This is for using math ops with 
// allowing you to put in as many expressions if you want
Interface* Parser::expression()
{
    // Either a number or expression is returned
    Interface* left = term();

    // Math operators, 0 is the id for term()
    left = ops(left, 0);
    return left;
}

// This handles with making an expression
// or passes an expression to be nested 
// or have the expression do a math op with a number
Interface* Parser::term()
{
    // Number or expression is returned
    Interface* left = factor();

    // Math operators, 1 is id for factor()
    left = ops(left, 1);
    return left;
}

// This is where the first part of the expression will fall into
// Here number tokens are made and return their values
// or an expression is returned
Interface* Parser::factor()
{
    Interface* result = nullptr;

    // A number is made
    if (_currentToken.token == Tokens::NUMBER)
    {
        result = AST->number(_currentToken.value);
        nextToken();
    }

    // An expression is made
    else if (_currentToken.token == Tokens::LPARTH)
    {
        nextToken();
        result = expression();
        if (_currentToken.token == Tokens::RPARTH) nextToken();
        else std::cerr << "Error: Missing a right parenthesis\n";
    }
    else
    {
        std::cerr << "Error: Invalid Token Detected\n";
        return result;
    }
    return result;
}

Interface *Parser::ops(Interface* left, int id)
{
    if (id == 1 || id == 0)
    {
        while (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS || _currentToken.token == Tokens::MULTIPLY)
        {
            int op = 0;
            if (_currentToken.token == Tokens::PLUS) op = 1;
            else if (_currentToken.token == Tokens::MINUS) op = 2;
            else if (_currentToken.token == Tokens::MULTIPLY) op = 3;
            else if (_currentToken.token == Tokens::DIVIDE) op = 4;
            nextToken();
            Interface* right;
            id ? right = factor() : right = term();
            left = AST->intOperator(op, left, right);
        }
    }
    return left;
}

// advance to the next token
void Parser::nextToken() {_currentToken = _tokenizer.getNextToken();}

// Starts the parsing
Interface* Parser::parse()
{
    nextToken();
    Interface* result = expression();
    if (_currentToken.token != Tokens::STOP)
    {
        std::cerr << "Error: Parser did not reach the end of the expression. Some tokens not found.\n";
        delete result;
        return nullptr;
    }

    return result;
}