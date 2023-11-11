#include "generate.h"

int main() 
{
    Tokens T;

    Generate G;
    G.generateCode("../random_code_c++.txt");
    std::cout <<G.generateVariables();
    return 0;
}