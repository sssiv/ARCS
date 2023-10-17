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
    while (std::isspace(_expression[_currentPos]) && _currentPos < _expression.size())
    {
        ++_currentPos;
    }

    // No Expression entered
    if (_currentPos > _expression.size())
    {
        std::cout << "No expression entered.\n";
        return Token(Tokens::STOP, -1);
    }

    // Takes in digit, 
    // stores its value 
    // returns it via Token struct
    while (std::isdigit(_expression[_currentPos]) || _expression[_currentPos] == '.')
    {
        std::string digit;
        while (_currentPos < _expression.size() && (std::isdigit(_expression[_currentPos]) || _expression[_currentPos] == '.') )
        {
            digit += _expression[_currentPos];
            ++_currentPos;
        }
        
        double value = std::stod(digit);
        return Token(Tokens::NUMBER, value);
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

    // Multiply
    else if (_expression[_currentPos] == '*')
    {
        ++_currentPos;
        return Token(Tokens::MULTIPLY, 3);
    }

    // Divide 
    else if (_expression[_currentPos] == '/')
    {
        ++_currentPos;
        return Token(Tokens::DIVIDE, 20);
    }

    /* Checking for Symbols */
    // (
    if (_expression[_currentPos] == '(')
    {
        ++_currentPos;
        return Token(Tokens::LPARTH, 4);
    }

    // )
    else if (_expression[_currentPos] == ')')
    {
        ++_currentPos;
        return Token(Tokens::RPARTH, 5);
    }
    
    // End of expression reached
    else if (_currentPos >= _expression.size())
    {
        std::cerr << "All tokens accounted for.\n";
        return Token(Tokens::STOP, -1);
    }
}