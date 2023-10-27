#include "test.h"

class Program : public Interface
{
private:
    Interface* _Result;
    Interface* _Test;
    Tokenizer* _Tokenizer;
    Parser* _Parser;
    std::string _expression;
    
public:
    Program();
    double evaluate() override;
    ~Program();
};