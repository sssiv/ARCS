#include "tokens.h"

Tokens::Tokens()
{
    read();
    //readCSV();
}

void Tokens::readCSV() 
{
    std::ifstream file("../tokens.csv");
    std::string line;

    // Check if file is open
    while (getline(file, line)) 
    {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (getline(lineStream, cell, ',')) 
            row.push_back(cell);
        _tokens.push_back(row);
    }
    file.close();
}

void Tokens::read() 
{
    // Make sure tokens.py ran first
    std::ifstream file("tokens.txt");
    std::string line;

    while (std::getline(file, line)) 
    {
        // In stream
        std::stringstream lineStream(line);

        // Individual input from lines
        std::string token;

        // Vector of each line from in stream
        std::vector<std::string> tokenList;

        while (std::getline(lineStream, token, ',')) 
        {
            // Trim leading whitespaces
            size_t start = token.find_first_not_of(" ");

            // Check if theres whitespaces
            start = (start == std::string::npos) ? 0 : start;
            
            // Trim trailing whitespace
            size_t end = token.find_last_not_of(" ");

            // Check if theres more whitespaces
            token = (end == std::string::npos) ? "" : token.substr(start, (end - start + 1));

            // Get line list
            tokenList.push_back(token);
        }

        // Push line list into the 2D vector
        _tokens.push_back(tokenList);
    }

    // Close text file
    file.close();
}

void Tokens::print()
{
    // // readCSV()
    // for (size_t column = 0; column < _tokens[0].size(); ++column)
    // {
    //     // Print column name
    //     std::cout << "Column: " << _tokens[0][column] << std::endl;
    //     for (size_t row = 1; row < _tokens.size(); ++row)
    //     {
    //         std::cout << _tokens[row][column] << std::endl;
    //     }
    //     std::cout << std::endl;
    // }

    // read() print
    for (size_t row = 0; row < _tokens.size(); ++row)
    {
        // First item in the row is the name of the column
        std::cout << "Section: " << _tokens[row][0] << std::endl;

        // Prints the rest of the row
        for (size_t column = 1; column < _tokens[row].size(); ++column)
            std::cout << _tokens[row][column] << std::endl;
        std::cout << std::endl;
    }

    // For a vector iterating through the 2D vector
    // for (const auto& vec : _tokens) 
    // {
    //     // For a string iterating through the vector thats looking at an individual column
    //     for (const std::string& token : vec) 
    //     {
    //         // Show the token
    //         std::cout << token << " ";
    //     }
    //     std::cout << std::endl;
    // }
}
