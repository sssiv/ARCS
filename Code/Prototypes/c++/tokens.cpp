#include "tokens.h"

using std::vector, std::string, std::ifstream, std::stringstream, std::cout;

void Tokens::readCSV() 
{
    ifstream file("../tokens.csv");
    string line;

    // Check if file is open
    while (getline(file, line)) 
    {
        vector<string> row;
        stringstream lineStream(line);
        string cell;

        while (getline(lineStream, cell, ',')) 
            row.push_back(cell);
        _tokens.push_back(row);
    }
    file.close();
}

void Tokens::read() 
{
    // Make sure tokens.py ran first
    ifstream file("tokens.txt");
    string line;

    while (std::getline(file, line)) 
    {
        // In stream
        stringstream lineStream(line);

        // Individual input from lines
        string token;

        // Vector of each line from in stream
        vector<string> tokenList;

        while (std::getline(lineStream, token, ',')) 
        {
            // Trim leading whitespaces
            size_t start = token.find_first_not_of(" ");

            // Check if theres whitespaces
            start = (start == string::npos) ? 0 : start;
            
            // Trim trailing whitespace
            size_t end = token.find_last_not_of(" ");

            // Check if theres more whitespaces
            token = (end == string::npos) ? "" : token.substr(start, (end - start + 1));

            // Get line list
            tokenList.push_back(token);
        }

        // Push line list into the 2D vector
        _tokens.push_back(tokenList);
    }

    // Close text file
    file.close();
}

Tokens::Tokens()
{
    read();
    //readCSV();
}

void Tokens::printTokens()
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
    // for (size_t row = 0; row < _tokens.size(); ++row)
    // {
    //     // Prints the rest of the row
    //     for (size_t column = 0; column < _tokens[row].size(); ++column)
    //         std::cout << _tokens[row][column] << std::endl;
    //     std::cout << std::endl;
    // }

    // read() print, ranged based
    // for (const auto& vec : _tokens) 
    // {
    //     // For a string iterating through the vector thats looking at an individual column
    //     for (const std::string& token : vec) 
    //     {
    //         std::cout << token << "  ";
    //     }
    //     std::cout << std::endl << std::endl;
    // }

    // read() print, better organization
    for (const auto& vec : _tokens) 
    {
        // For a string iterating through the vector thats looking at an individual column
        for (size_t i = 0; i < vec.size(); ++i) 
        {
            i < vec.size() - 1 ? cout << vec[i] << ", " : cout << vec[i] << " ";
        }
        cout << "\n\n";
    }
}