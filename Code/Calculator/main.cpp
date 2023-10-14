#include "parser.h"

int main()
{
    std::string expression;
    std::cout << "Enter an expression: ";

    std::getline(std::cin, expression);
    Tokenizer tokenizer(expression);
    Parser parser(tokenizer);

    ASTNode* result = parser.parse();

    if (result != nullptr)
    {
        std::cout << "Result: " << result->evaluate() << std::endl;
        delete result;
    }
    else
    {
        std::cerr << "Error with result.\n";
    }
}