#include "generate.h"

int main() 
{
    Generate gen;
    gen.generateRandomTokens("../fail/c++random_Token.txt");
    gen.generateCode("../pass/c++random_Code.txt");
    
    return 0;
}