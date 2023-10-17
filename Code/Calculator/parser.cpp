#include "parser.h"

Parser::Parser(Tokenizer& tokenizer) : _tokenizer(tokenizer) {}

Interface* Parser::expression()
{
    Interface* left = term();

    while (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS || _currentToken.token == Tokens::MULTIPLY || _currentToken.token == Tokens::DIVIDE)
    {
        char op = ' ';
        if (_currentToken.token == Tokens::PLUS)
        {
            op = '+';
        }
        else if (_currentToken.token == Tokens::MINUS)
        {
            op = '-';
        }
        else if (_currentToken.token == Tokens::MULTIPLY)
        {
            op = '*';
        }
        else if (_currentToken.token == Tokens::DIVIDE)
        {
            op = '/';
        }
        nextToken();
        Interface* right = term();
        left = AST->intOperator(op, left, right);
    }
    
    return left;
}

Interface* Parser::term()
{
    Interface* left = factor();

    while (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS || _currentToken.token == Tokens::MULTIPLY)
    {
        char op = ' ';
        if (_currentToken.token == Tokens::PLUS)
        {
            op = '+';
        }
        else if (_currentToken.token == Tokens::MINUS)
        {
            op = '-';
        }
        else if (_currentToken.token == Tokens::MULTIPLY)
        {
            op = '*';
        }
        nextToken();
        Interface* right = factor();
        left = AST->intOperator(op, left, right);
    }

    return left;
}

Interface* Parser::factor()
{
    Interface* result = nullptr;

    if (_currentToken.token == Tokens::NUMBER)
    {
        result = AST->number(_currentToken.value);
        nextToken();
    }
    else if (_currentToken.token == Tokens::LPARTH)
    {
        nextToken();
        result = expression();
        if (_currentToken.token == Tokens::RPARTH)
        {
            nextToken();
        }
        else
        {
            std::cerr << "Error: Missing a right parenthesis\n";
        }
    }
    else
    {
        std::cerr << "Error: Invalid Token Detected\n";
    }
    return result;
}

// advance to the next token
void Parser::nextToken() {_currentToken = _tokenizer.getNextToken();}

Interface* Parser::parse()
{
    nextToken();
    Interface* result = expression();
    if (_currentToken.token != Tokens::STOP)
    {
        std::cerr << "Error: Parser did not reach the end of the expression. Some tokens not found.\n";
    }

    return result;
}