#include "generate.h"

int main() 
{
    Generate gen;
    gen.generateCode("../pass/c++code.txt");
    Tokens tokens;
    tokens.print();
    return 0;
}