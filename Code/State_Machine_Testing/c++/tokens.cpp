#include "tokens.h"

Tokens::Tokens(){read();}

/*
void Tokens::readCSV() 
{
    std::vector<std::vector<str>> data;
    std::ifstream file("../tokens.csv");
    std::string line;

    while (std::getline(file, line)) 
    {
        std::stringstream lineStream(line);
        str cell;
        std::vector<str> parsedRow;
        bool nullValueFound = false;
        while (std::getline(lineStream, cell, ',')) 
        {
            // Define your null value condition here
            if (cell.empty() || cell == "NULL") 
            {  
                nullValueFound = true;
                break;
            }
            parsedRow.push_back(cell);
        }

        if (!nullValueFound) 
        {
            _tokens.push_back(parsedRow);
        }
    }
}


void Tokens::print()
{
    // For a vector iterating through the 2D vector
    for (const auto& vec : _tokens) 
    {
        // For a string iterating through the vector thats looking at an individual column
        for (const str& token : vec) 
        {
            // Show the token
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}
*/