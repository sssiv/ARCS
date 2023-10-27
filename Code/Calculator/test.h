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
    int _pass;
    int _fail;
    int rand_between(const int&, const int&);

    void testOps();
    void testTokenizer();
    void testParser();
    void testAST();

public:
    Test();
    double evaluate() override;
    ~Test();
};
