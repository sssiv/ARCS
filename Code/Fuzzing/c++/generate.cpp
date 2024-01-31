#include "generate.h"

using std::vector, std::string, std::ofstream;

Generate::Generate()
{
    // Empty string to write code
    _code = "";
};

// random randoms to random file randomly
void Generate::generateRandomTokens(const string& file)
{
    // Create and open a text file
    ofstream MyFile(file);

    // Set total limit of written tokens
    int limit = rand_between(10000, 100000);

    // Counter for current line length
    int lineLength = 0;

    // String to collect all random tokens
    string tokens = "";
    
    // Having not hit the limit
    while (tokens.size() < limit)
    {
        // Each code line length is between 1 - 1,000 characters long
        if (lineLength >= rand_between(1, 1000))
        {
            // Randomly Decide if we want a space, tab, or new line
            if (rand_between(0, 1))
            {
                // Randomly choose space, tab, or new line
                switch (rand_between(0, 2))
                {
                    case 0: tokens += " "; break;
                    case 1: tokens += "\t"; break;
                    case 2: tokens += "\n"; break;    
                    default: break;
                }
            }
            // Re-set line legnth counter
            lineLength = 0;
        }

        // all the other tokens that are not space, tab, or new line
        else
        {
            // Select random list before name inputs
            // !! Here is the fault !!
            vector<string> selectedList = _Tokens.getTokens()[rand_between(0, Indices::PUNCTUATION)];
        
            // Random string from selected list
            tokens += selectedList[rand_between(0, selectedList.size() - 1)];

            // Length added to compare to limit
            lineLength += tokens.size();
        }
    }
    
    // Write strings to file
    MyFile << tokens;

    // Close the file
    MyFile.close();   
}