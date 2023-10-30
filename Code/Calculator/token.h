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

    // All the characters for each token except stop
    struct TokenChar
    {
        static inline const char zero = '0';
        static inline const char one = '1';
        static inline const char two = '2';
        static inline const char three = '3';
        static inline const char four = '4';
        static inline const char five = '5';
        static inline const char six = '6';
        static inline const char seven = '7';
        static inline const char eight = '8';
        static inline const char nine = '9';

        static inline const char plus = '+';
        static inline const char minus = '-';
        static inline const char multiply = '*';
        static inline const char divide = '/';
        static inline const char leftParth = '(';
        static inline const char rightParth = ')';
    } TokenList;
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

public:
    // A Parser object will take in the token class with the expression
    Tokenizer(const std::string&);      
    
    // itr's through each token as we evaluate the expression
    Token* getNextToken();              
};