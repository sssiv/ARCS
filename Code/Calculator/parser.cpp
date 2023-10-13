#include "parser.h"

Parser::Parser(Tokenizer& T) : _tokenizer(T) {}

// expression ::= term | {"+" | "-"} term
double Parser::expression()
{
    double left = term();

    if (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS)
    {
        Tokens prevToken = _currentToken.token;
        nextToken();
        double right = term();

        if (prevToken == Tokens::PLUS)
        {
            left += right;
        }
        else if (prevToken == Tokens::MINUS)
        {
            left -= right;
        }

        return left;
    }

    return left;
}

// term ::= factor | {"+" | "-"} factor
double Parser::term()
{
    double left = factor();

    if (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS)
    {
        Tokens prevToken = _currentToken.token;
        nextToken();
        double right = factor();

        if (prevToken == Tokens::PLUS)
        {
            left += right;
        }
        else if (prevToken == Tokens::MINUS)
        {
            left -= right;
        }

        return left;
    }

    return left;
}

// factor ::= Number | "(" expression "")"
double Parser::factor()
{
    //double left = expression();

    if (_currentToken.token == Tokens::NUMBER)
    {
        double value = _currentToken.value;
        nextToken();
        return value;
    }
    else if (_currentToken.token == Tokens::LPARTH)
    {
        nextToken();
        double result = expression();

        if(_currentToken.token != Tokens::RPARTH)
        {
            std::cerr << "Missing a right parentheses\n";
        }

        nextToken();
        return result;
    }
    else
        std::cerr << "Invalid Token Detected\n";

}

// advance to the next token
void Parser::nextToken() {_currentToken = _tokenizer.getNextToken();}

// Where the parsing processes
double Parser::parse()
{
    nextToken();
    double result = expression();

    if(_currentToken.token != Tokens::STOP)
    {
        std::cerr << "All tokens accounted for\n";
    }
    else
        std::cerr << "Parser did not reach the end of the expression. Some tokens not found.\n Git Good, Skill Issue\n";

    return result;
}