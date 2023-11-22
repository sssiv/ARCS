#include "variables.h"

void Variables::makeNamesAndTypes()
{   
    // List of Variable types and Names
    std::vector<std::string> allNames = _tokens[Indices::VARIABLE_NAMES];

    // // Shuffle the list of names to randomize their order.
    std::shuffle(allNames.begin(), allNames.end(), std::default_random_engine(std::random_device()()));
    
    // How many variables to randomly generate based on how many names avaliable
    int numOfVariables = rand_between(1, Indices::VARIABLE_NAMES);
    
    // The list is shuffled, so no need to check for uniquness
    std::vector<std::string> selectedNames(allNames.begin(), allNames.begin() + numOfVariables);

    // Push Variable name and Type pair into the vector
    for (const std::string& name : selectedNames)
    {
        std::string type = _tokens[Indices::VARIABLES][rand_between(0, _tokens[Indices::VARIABLES].size() - 1)];
        std::string value = makeValue(type);
        _variables.push_back(std::make_tuple(type, name, value));   
    }
}

Variables::Variables()
{
    _tokens = _Tokens.getTokens();
    makeNamesAndTypes();
}

// Needs testing, used when reinitialized variables are in states
void Variables::makeNewValues(std::vector<std::tuple<std::string, std::string, std::string>>& tokens)
{
    for (auto&[type, name, value] : tokens)
        // Changes value by passing in its own type
        value = makeValue(type);
}

// Needs testing, Should make a new value when found
void Variables::makeNewValue(const std::string& target, std::vector<std::tuple<std::string, std::string, std::string>>& tokens)
{
    for (auto&[type, name, value] : tokens)
        if (name == target)
            value = makeValue(type);
}

// Returns int, string, or bool initializations
std::string Variables::makeValue(const std::string& type)
{
    if (type == "int")
    {
        return std::to_string(rand_between(0, 420));
    }

    // Uses index of all string inputs from tokens 
    if (type == "string")
    {
        std::vector<std::string> stringInputs = _tokens[Indices::STRING_INPUT];
        return "\"" + stringInputs[rand_between(1, stringInputs.size() - 1)] + "\"";
    }

    if (type == "bool")
    {
        return (rand_between(0, 1)) ? "True" : "False";
    }  

    return std::string();
}

Variables::~Variables()
{
}
