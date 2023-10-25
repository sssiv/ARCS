#include "program.h"

int main()
{
    Interface* program = new Program;
    program->evaluate();
    delete program;
}