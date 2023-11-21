#include "generate.h"

Generate::Generate()
{
    // Get all code data
    _tokens = _Tokens.getTokens();
    _events = _Events.getEvents();
    _variables = _Variables.getVariables();
    
    // Empty string to write code
    _code = "";
};

std::string Generate::generateEvents()
{
    // Empty string to write events
    std::string code = "Events: \n";

    // Write events
    for (const auto& event : _events)
    {
        code += event.first + " {" + event.second + "};\n";
    }
    code += "\n";

    // Return events
    return code;
}

std::string Generate::generateVariables()
{
    // Empty string to write variables
    std::string code = "";

    code += "Variables: \n";

    // Write Variables
    for (const auto& variable : _variables)
    {
        code += std::get<0>(variable) + " " + std::get<1>(variable) + " = " + std::get<2>(variable) + ";\n";
    }
    code += "\n";

    code += "New Values: \n";
    // Write new Variable values
    _Variables.makeNewValues(_variables);
    for (const auto& variable : _variables)
    {
        code += std::get<1>(variable) + " = " + std::get<2>(variable) + ";\n";
    }
    code += "\n";

    // Return variables
    return code;
}

std::string Generate::generateActors()
{
    return "";
}

std::string Generate::generateStatemachine()
{
    return "";
}

std::string Generate::generateStates()
{
    return "";
}

// Makes complete proteus code
void Generate::generateCode(const std::string& file)
{
    // Create and open a text file
    std::ofstream MyFile(file);

    // Generate events first
    _code += generateEvents();

    // Actor

    // Variables
    _code += generateVariables();

    //States
    
    // Writes code
    MyFile << _code;

    // Close the file
    MyFile.close();
}

void Generate::generateRandomTokens(const std::string& file)
{
    // Create and open a text file
    std::ofstream MyFile(file);

    // Set total limit of written tokens
    int limit = rand_between(10000, 100000);

    // Counter for current line length
    int lineLength = 0;

    // String to collect of random tokens
    std::string tokens = "";
    
    // Having not hit the limit
    while (tokens.size() < limit)
    {
        // Each code line length is between 1 - 1,000
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
            std::vector<std::string> selectedList = _tokens[rand_between(0, Indices::PUNCTUATION)];

            // Size of seleced List
            int listSize = selectedList.size();

            // Random string from selected list
            tokens += selectedList[rand_between(0, listSize - 1)];

            // Length added to compare to limit
            lineLength += tokens.size();
        }
        
    }
    
    // Write strings to file
    MyFile << tokens;

    // Close the file
    MyFile.close();   
}