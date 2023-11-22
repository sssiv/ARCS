#include "generate.h"

int main() 
{
    Generate gen;
    gen.generateRandomTokens("../fail/c++random_Token.txt");
    gen.generateRandomCode("../pass/c++random_Code.txt");
    
    return 0;
}