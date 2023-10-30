#include "program.h"

Program::Program() {}

// Collects expression input
// tokenizes expression
// parses expression
// runs tests (optional)
// displays result
// deletes memory Test, Tokenizer, Parser, Result
double Program::evaluate()
{
    // get expression
    std::cout << "Enter an expression: ";
    std::getline(std::cin, _expression);

    // objects to handle the expression
    _Test = new Test;
    _Tokenizer = new Tokenizer(_expression);
    _Parser = new Parser(_Tokenizer);
    _Result = _Parser->parse();

    // Says the parser actually returned something
    if (_Result != nullptr)
    {
        // guarantees that the result we get is a processed number
        if (!std::isnan(_Result->evaluate()))
            std::cout << "Result: " << _Result->evaluate() << std::endl;
        else
            std::cerr << "Result: Invalid" <<  std::endl;
    }
    else std::cerr << "Error: No result returned.\n";

    // Run tests
    _Test->evaluate();

    // delete memory
    delete _Result, _Tokenizer, _Parser, _Test;
    return 0.0;
}

// I deleted memory twice cause I dont trust myself
Program::~Program()
{
    delete _Result, _Tokenizer, _Parser, _Test;
}
