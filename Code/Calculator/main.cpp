#include "parser.h"

int main()
{
    std::string expression;
    std::cout << "Enter an expression: ";

    std::getline(std::cin, expression);
    Tokenizer tokenizer(expression);
    Parser parser(tokenizer);

    double result = parser.parse();

    if(!std::isnan(result))
        std::cerr << result << std::endl;
    else
        std::cerr << "Error with result. Skill issue, git gud, try not sucking.\n";
}