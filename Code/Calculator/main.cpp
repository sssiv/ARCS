#include "parser.h"

int main()
{
    std::string expression;
    std::cout << "Enter an expression: ";

    std::getline(std::cin, expression);
    Tokenizer tokenizer(expression);
    Parser parser(&tokenizer);

    Interface* result = parser.parse();

    if (result != nullptr)
    {
        if (!std::isnan(result->evaluate()))
            std::cout << "Result: " << result->evaluate() << std::endl;
        else
            std::cerr << "Result: Invalid" <<  std::endl;
        delete result;
    }
    else
    {
        std::cerr << "Error: No result returned.\n";
    }

    //Not sure why this loop isnt working
    // char c = 'y';
    // while (c == 'y')
    // {
    //     std::string expression;
    //     std::cout << "Enter an expression: ";
    //     std::getline(std::cin, expression);
    //     Tokenizer tokenizer(expression);
    //     Parser parser(tokenizer);
    //     Interface* result = parser.parse();
    //     if (result != nullptr)
    //     {
    //         if (!std::isnan(result->evaluate()))
    //             std::cout << "Result: " << result->evaluate() << std::endl;
    //         else
    //             std::cout << "Result: Invalid" <<  std::endl;
    //         delete result;
    //     }
    //     else
    //     {
    //         std::cerr << "Error: No result returned.\n";
    //     }
    //     std::cout << "Another one? ";
    //     std::cin >> c;
    // }
}