#include "token.h"

Token::Token() {}

//  Token ENUM value
//  Value of the token (So far I've only used this to hold a numbers value)
Token::Token(const Tokens& t, const double& v) : token(t), value(v) {}

//double Token::getValue() {return value;}

//Tokens Token::getToken() {return token;}

/********************************************************************************************************************/

// replaces std::isdigit so that I can use my tokens instead
bool Tokenizer::isNumber(const char& c)
{
    switch (c) 
    {
        case Token::TokenChar::zero:
        case Token::TokenChar::one:
        case Token::TokenChar::two:
        case Token::TokenChar::three:
        case Token::TokenChar::four:
        case Token::TokenChar::five:
        case Token::TokenChar::six:
        case Token::TokenChar::seven:
        case Token::TokenChar::eight:
        case Token::TokenChar::nine:
            return true;
        default:
            return false;
    }
}

// Default Constructor - Takes in the expression
Tokenizer::Tokenizer(const std::string& input) : _expression(input), _currentPos(0) {}

// Goes through expression input until it finds a number of character
Token* Tokenizer::getNextToken()
{
    // Skip whitespaces
    while (std::isspace(_expression[_currentPos]) && _currentPos < _expression.size())
    {
        ++_currentPos;
        // No Expression entered
        if (_currentPos >= _expression.size())
        {
            std::cout << "No expression entered.\n";
            return new Token(Tokens::STOP, -1);
        }
    }

    // Takes in digit, 
    // stores its value 
    // returns it via Token struct

    // Something is wrong in this loop
    // Tests made me look at it
    // isNumber(_expression[_currentPos]), std::isdigit(_expression[_currentPos])
    bool decimal = false;
    while (isNumber(_expression[_currentPos]) || _expression[_currentPos] == '.')
    {
        std::string digit;
        while (_currentPos < _expression.size() && (isNumber(_expression[_currentPos]) || (_expression[_currentPos] == '.' && !decimal)) )
        {
            if (_expression[_currentPos] == '.')
            {
                // doesnt seem to work
                // if (decimal)
                // {
                //     std::cerr << "Multiple decimals found. Can only have one\n";
                //     return new Token(Tokens::STOP, -1);
                // }
                decimal = true;
            }
            digit += _expression[_currentPos];
            ++_currentPos;
        }
        return new Token(Tokens::NUMBER, std::stod(digit));
    }

    /* Checking for Math operators */
    // Plus
    if (_expression[_currentPos] == Token::TokenChar::plus)
    {
        ++_currentPos;
        return new Token(Tokens::PLUS, 1);
    }

    //Minus
    else if (_expression[_currentPos] == Token::TokenChar::minus)
    {
        ++_currentPos;
        return new Token(Tokens::MINUS, 2);
    }

    // Multiply
    else if (_expression[_currentPos] == Token::TokenChar::multiply)
    {
        ++_currentPos;
        return new Token(Tokens::MULTIPLY, 3);
    }

    // Divide 
    else if (_expression[_currentPos] == Token::TokenChar::divide)
    {
        ++_currentPos;
        return new Token(Tokens::DIVIDE, 4);
    }

    /* Checking for Symbols */
    // (
    if (_expression[_currentPos] == Token::TokenChar::leftParth)
    {
        ++_currentPos;
        return new Token(Tokens::LPARTH, 5);
    }

    // )
    else if (_expression[_currentPos] == Token::TokenChar::rightParth)
    {
        ++_currentPos;
        return new Token(Tokens::RPARTH, 6);
    }
    
    // End of expression reached
    else if (_currentPos == _expression.size())
    {
        //std::cout << "All tokens accounted for\n";
        return new Token(Tokens::STOP, -1);
    }
    return new Token(Tokens::STOP, -1);
}