#include "tokens.h"

Tokens::Tokens(){read();}

std::vector<std::vector<str>> Tokens::getTokens() {return _tokens;}

void Tokens::readCSV() 
{
    std::vector<std::vector<str>> data;
    std::ifstream file("tokens.csv");
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
void Tokens::read()
{
    // Token text file made from python
    std::ifstream file("../tokens.txt");

    // Used to read in each line
    str line;

    // From file, input to line
    while (std::getline(file, line))
    {
        // Used for individual tokens
        str token;

        // Temp vector for making a vector for the 2D vector
        std::vector<str> v;

        // Set iss to read in from line variable
        std::istringstream iss(line);

        // Continue reading while there is a toke in that line
        while (iss >> token) 
            // Save what we read in
            v.push_back(token);

        // Push new line into the 2D vector
        _tokens.push_back(v);
    }

    // Close file
    file.close();
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