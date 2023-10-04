#include "token.h"

Token::Token()
{
    readFile();
};

// Code File input
void Token::readFile()
{
    std::string myLine;
    myFile.open("syntax.txt");

    // Read in the Code
    if(myFile.is_open())
    {
        while(std::getline(myFile, myLine))
        {
            // Skip blank lines
            if(!std::all_of(myLine.begin(), myLine.end(), isspace)) 
                syntaxLines.push_back(myLine);
        }
    }
}

void Token::Print()
{
    for(int i = 0; i < syntaxLines.size(); ++i)
        std::cout << syntaxLines[i] << '\n';

}
