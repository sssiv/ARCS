#pragma once

#include <string>
#include <iostream>

// List of all tokens
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
    // Does this constructor need to be 'explicit' ?
    Token(const Tokens&, const double&);  // Takes in Tokens/enum and its value

    inline double getValue() {return value;};
    inline Tokens getToken() {return token;};

    // All the characters for each token except stop
    // If theres issues, just make this struct seperate from any class
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
    size_t _currentPos;                 // Counter as we itr through the expression

    bool isNumber(const char&);

public:
    Tokenizer(const std::string&);      // A Parser object will take in the token class with the expression
    Token* getNextToken();              // This itr's through each token as we evaluate the expression
};