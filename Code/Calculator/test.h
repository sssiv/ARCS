#pragma once

#include "parser.h"
#include <random>
#include <chrono>

// Test runner class, inherits Interface
class Test : public Interface
{
private:
    Tokenizer* _Tokenizer;
    Parser* _Parser;
    ASTNode* _AST;

    int _numOfTests;
    int _pass;
    int _fail;
    int rand_between(const int&, const int&);

    // Expression generator
    std::string randomExpression();

    // Test node classes
    void testOps();

    // uses AST to test input
    void testAST();

    // Tests tokenizing results
    void testTokenizer();

    // Tests the running result of the parser
    void testParser();
    
public:
    Test();
    double evaluate() override;
    ~Test();
};
