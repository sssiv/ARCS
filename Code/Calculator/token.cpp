#include "token.h"

// Default Constructors for Struct 
Token::Token(){}
//  * Token ENUM value
//  * Value of the token (So far I've only used this to hold a numbers value)
Token::Token(Tokens t, double v) : token(t), value(v) {}

// Default Constructor - Takes in the expression
Tokenizer::Tokenizer(const std::string& input) : _expression(input), _currentPos(0) {}

// Goes through expression input until it finds a number of character
Token Tokenizer::getNextToken()
{
    // Skip whitespaces
    while (isspace(_expression[_currentPos]) && _currentPos < _expression.size())
    {
        ++_currentPos;
    }

    // No Expression entered
    if (_currentPos >= _expression.size())
    {
        std::cout << "No expression entered.\n";
        return Token(Tokens::STOP, -1);
    }
    
    /* Checking for Math operators */
    // Plus
    if (_expression[_currentPos] == '+')
    {
        ++_currentPos;
        return Token(Tokens::PLUS, 1);
    }

    //Minus
    else if (_expression[_currentPos] == '-')
    {
        ++_currentPos;
        return Token(Tokens::MINUS, 2);
    }

    /* Checking for Symbols */
    // (
    if (_expression[_currentPos] == '(')
    {
        ++_currentPos;
        return Token(Tokens::LPARTH, 3);
    }

    // )
    else if (_expression[_currentPos] == ')')
    {
        ++_currentPos;
        return Token(Tokens::RPARTH, 4);
    }
    
    // No valid tokens found tokens found
    std::cerr << "No Valid Tokens Found.\n";
    return Token(Tokens::STOP, -1);
}