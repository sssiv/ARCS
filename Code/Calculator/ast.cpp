#include "ast.h"

ASTNode::ASTNode() {}

Interface *ASTNode::newNumber(const double& value)
{
    return new NumberNode(value);
}

Interface *ASTNode::intOperator(const int& op, Interface* left, Interface* right)
{
    return new OperatorNode(op, left, right);
}

// This is for using math ops with 
// allowing you to put in as many expressions if you want
Interface* ASTNode::expression()
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
Interface* ASTNode::term()
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
Interface* ASTNode::factor()
{
    Interface* result = nullptr;

    // A number is made
    if (_currentToken->getToken() == Tokens::NUMBER)
    {
        result = newNumber(_currentToken->getValue());
        nextToken();
    }

    // An expression is made
    else if (_currentToken->getToken() == Tokens::LPARTH)
    {
        nextToken();
        result = expression();
        if (_currentToken->getToken() == Tokens::RPARTH) nextToken();
        else std::cerr << "Error: Missing a right parenthesis\n";
    }
    else
    {
        std::cerr << "Error: Invalid Token Detected\n";
        return result;
    }
    return result;
}

Interface *ASTNode::ops(Interface* left, const int& id)
{
    // 1 - RHS is a factor
    // 0 = RHS is a term
    if (id == 1 || id == 0)
    {
        while (_currentToken->getToken() == Tokens::PLUS || _currentToken->getToken() == Tokens::MINUS 
        || _currentToken->getToken() == Tokens::MULTIPLY || _currentToken->getToken() == Tokens::DIVIDE)
        {
            int op = 0;
            if (_currentToken->getToken() == Tokens::PLUS) op = 1;
            else if (_currentToken->getToken() == Tokens::MINUS) op = 2;
            else if (_currentToken->getToken() == Tokens::MULTIPLY) op = 3;
            else if (_currentToken->getToken() == Tokens::DIVIDE) op = 4;
            nextToken();
            Interface* right;
            id ? right = factor() : right = term();
            left = intOperator(op, left, right);
        }
    }
    return left;
}

void ASTNode::getTokens(Tokenizer* tokenizer) {_tokenizer = tokenizer;}

// advance to the next token
void ASTNode::nextToken() 
{
    delete _currentToken;
    _currentToken = _tokenizer->getNextToken();
}

bool ASTNode::stopCheck() {return _currentToken == nullptr;}

ASTNode::~ASTNode() {}