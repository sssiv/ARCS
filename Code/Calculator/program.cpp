#include "program.h"

// Program object is made, and program 
// doesnt continue until it gets uers input
Program::Program()
{
    std::cout << "Enter an expression: ";
    std::getline(std::cin, _expression);

    _Test = new Test;
    _Tokenizer = new Tokenizer(_expression);
    _Parser = new Parser(_Tokenizer);
    _Result = _Parser->parse();
}

double Program::evaluate()
{
    if (_Result != nullptr)
    {
        if (!std::isnan(_Result->evaluate()))
            std::cout << "Result: " << _Result->evaluate() << std::endl;
        else
            std::cerr << "Result: Invalid" <<  std::endl;
    }
    else
    {
        std::cerr << "Error: No result returned.\n";
    }

    _Test->evaluate();
    delete _Result, _Tokenizer, _Parser, _Test;
    return 0.0;
}

// I deleted memory twice cause I dont trust myself
Program::~Program()
{
    delete _Result, _Tokenizer, _Parser, _Test;
}
