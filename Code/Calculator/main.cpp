#include "test.h"

int main()
{
    Interface* program = new Program;
    Interface* test = new Test;

    program->evaluate();
    test->evaluate();
    
    delete program, test;
}