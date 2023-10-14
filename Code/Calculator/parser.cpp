#include "parser.h"

Parser::Parser(Tokenizer& tokenizer) : _tokenizer(tokenizer) {}

/*
// expression ::= term | {"+" | "-"} term
double Parser::expression()
{
    double left = term();

    while (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS)
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

    while (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS)
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
    while (_currentToken.token == Tokens::NUMBER)
    {
        double value = _currentToken.value;
        nextToken();
        return value;
    }
    if (_currentToken.token == Tokens::LPARTH)
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
*/

ASTNode* Parser::expression()
{
    ASTNode* left = term();

    while (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS)
    {
        char op = (_currentToken.token == Tokens::PLUS) ? '+' : '-';
        nextToken();
        ASTNode* right = term();
        left = new OperatorNode(op, left, right);
    }

    return left;
}

ASTNode* Parser::term()
{
    ASTNode* left = factor();

    while (_currentToken.token == Tokens::PLUS || _currentToken.token == Tokens::MINUS)
    {
        char op = (_currentToken.token == Tokens::PLUS) ? '+' : '-';
        nextToken();
        ASTNode* right = factor();
        left = new OperatorNode(op, left, right);
    }

    return left;
}

ASTNode* Parser::factor()
{
    ASTNode* result = nullptr;

    if (_currentToken.token == Tokens::NUMBER)
    {
        result = new NumberNode(_currentToken.value);
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
            std::cerr << "Missing a right parenthesis\n";
        }
    }
    else
    {
        std::cerr << "Invalid Token Detected\n";
    }

    return result;
}

// advance to the next token
void Parser::nextToken() {_currentToken = _tokenizer.getNextToken();}

/*
// Where the parsing processes
double Parser::parse()
{
    nextToken();
    double result = expression();

    if (_currentToken.token != Tokens::STOP)
    {
        std::cerr << "All tokens accounted for\n";
    }
    else
        std::cerr << "Parser did not reach the end of the expression. Some tokens not found.\n Git Good, Skill Issue\n";

    return result;
}
*/

ASTNode* Parser::parse()
{
    nextToken();
    ASTNode* result = expression();

    if (_currentToken.token != Tokens::STOP)
    {
        std::cerr << "Parser did not reach the end of the expression. Some tokens not found.\n";
    }

    return result;
}