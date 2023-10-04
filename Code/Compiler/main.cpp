#include "func.h"

int main()
{
    Vars V;
    Print();
    V.init();
    std::cout << V.tokens[0];
    return 0;
}