#pragma once

#include "parser.h"
#include <random>
#include <chrono>

class Test : public Interface
{
private:
    Tokenizer* _Tokenizer;
    Parser* _Parser;
    ASTNode* _AST;
    int _numOfTests;
    int rand_between(int, int);

    void testOps();
    void testTokenizer();
    void testParser();
    void testAST();
    
public:
    Test();
    double evaluate() override;
    ~Test();
};
