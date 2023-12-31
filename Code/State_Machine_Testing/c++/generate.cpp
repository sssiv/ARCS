#include "generate.h"

using std::vector, std::string, std::ofstream;

Generate::Generate()
{
    // Get all code data
    _tokens = _Tokens.getTokens();
    _events = _Events.getEvents();
    _variables = _Variables.getVariables();
    
    // Empty string to write code
    _code = "";
};

string Generate::generateEvents()
{
    // Empty string to write events
    string code = "";

    // Write events
    for (const auto&[name, type] : _events)
    {                     
        code += "event " + name + " {" + type + "};\n";
    }
    code += "\n";

    // Return events
    return code;
}

string Generate::generateVariables()
{
    // Empty string to write variables
    string code = "";

    // Write Variables
    code += "Variables: \n";
    for (const auto&[type, name, value] : _variables)
    {      
        code += type + " " + name + " = " + value + ";\n";
    }
    code += "\n";

    // Write new Variable values
    code += "New Values: \n";
    _Variables.makeNewValues(_variables);
    for (const auto&[type, name, value] : _variables)
    {               
        code += name + " = " + value + ";\n";
    }
    code += "\n";

    // Return variables
    return code;
}

// Can an actor have multiple statemachines?
string Generate::generateActors()
{
    // List of actor names
    vector<string> actorNames = _tokens[Indices::ACTOR_NAMES];

    // Random name from the list
    string randName = actorNames[rand_between(0, actorNames.size() - 1)];

    // Actor syntax
    string actor = "actor " + randName + " {\n";

    // Return syntax with name
    return actor;
}

string Generate::generateStatemachine()
{
    return string();
}

string Generate::generateStates()
{
    return string();
}

// Makes complete proteus code
void Generate::generateRandomCode(const string& file)
{
    // Create and open a text file
    ofstream MyFile(file);

    // Generate events first
    _code += generateEvents();

    // Actor
    _code += generateActors();

    // Variables
    _code += generateVariables();

    // Close actor (for now)
    _code += "}\n";

    //States
    
    // Writes code
    MyFile << _code;

    // Close the file
    MyFile.close();
}

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
            vector<string> selectedList = _tokens[rand_between(0, Indices::PUNCTUATION)];

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