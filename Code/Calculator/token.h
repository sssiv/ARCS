#pragma once

#include <string>
#include <iostream>

// Enum list of all tokens
enum class Tokens 
{
    NUMBER, 
    PLUS, MINUS, MULTIPLY, DIVIDE, 
    LPARTH, RPARTH, 
    STOP
};

    // All the characters for each token except stop
struct TokenChar
{
    static constexpr char const zero = '0';
    static constexpr char const one = '1';
    static constexpr char const two = '2';
    static constexpr char const three = '3';
    static constexpr char const four = '4';
    static constexpr char const five = '5';
    static constexpr char const six = '6';
    static constexpr char const seven = '7';
    static constexpr char const eight = '8';
    static constexpr char const nine = '9';

    static constexpr char const plus = '+';
    static constexpr char const minus = '-';
    static constexpr char const multiply = '*';
    static constexpr char const divide = '/';
    static constexpr char const leftParth = '(';
    static constexpr char const rightParth = ')';
};

// Current Token Holder
class Token
{
private:
    Tokens token;   // Current Token
    double value;   // Tokens Value

public:
    Token();

    // Takes in Tokens enum marker and its hash value
    Token(const Tokens&, const double&);  

    // If its an int, it returns its integer value
    // else it will return the operators hash value
    inline double getValue() {return value;};

    // current enum token marker
    inline Tokens getToken() {return token;};
};

// Holds the input expression
// Gives each token when needed
class Tokenizer
{
private:
    const std::string& _expression;     // The overall input expression
    size_t _currentPos;                 // expression string index

    // used to check if the current index in 
    // the expression string in a number
    bool isNumber(const char&);

    //Checking if we are currently looking at an operator
    bool isOperator(const char&);

    // Checking if we are looking at any parentheses
    bool isParth(const char&);

public:
    // A Parser object will take in the token class with the expression
    Tokenizer(const std::string&);      
    
    // itr's through each token as we evaluate the expression
    Token* getNextToken();              
};