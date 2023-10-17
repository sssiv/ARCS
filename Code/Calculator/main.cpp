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
        if (!std::isnan(result->evaluate()))
            std::cout << "Result: " << result->evaluate() << std::endl;
        else
            std::cout << "Result: Invalid" <<  std::endl;
        delete result;
    }
    else
    {
        std::cerr << "Error: No result returned.\n";
    }
}