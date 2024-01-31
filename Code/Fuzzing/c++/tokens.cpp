#include "tokens.h"

using std::vector, std::string, std::ifstream, std::stringstream, std::cout;

// Using the CSV file to read in tokens
void Tokens::readCSV() 
{
    ifstream file("../tokens.csv");
    string line;

    // While data comes in
    while (getline(file, line)) 
    {
        // Vector for the first line of tokens
        vector<string> row;

        // In stream
        stringstream lineStream(line);

        // Current cell input from the CSV
        string cell;

        // While data is inputted for each cell in the line
        while (getline(lineStream, cell, ',')) 
            row.push_back(cell);
        
        // Save the line of tokens
        _tokens.push_back(row);
    }

    // Close file to prevent memory leaks
    file.close();
}

// Using the textfile to read in tokens 
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
    //readCSV();
    read();
}

void Tokens::printTokens()
{
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