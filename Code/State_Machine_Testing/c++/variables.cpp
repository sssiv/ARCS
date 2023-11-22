#include "variables.h"

using std::vector, std::string, std::tuple;

void Variables::makeNamesAndTypes()
{   
    // List of Variable types and Names
    vector<string> allNames = _tokens[Indices::VARIABLE_NAMES];

    // // Shuffle the list of names to randomize their order.
    std::shuffle(allNames.begin(), allNames.end(), std::default_random_engine(std::random_device()()));
    
    // How many variables to randomly generate based on how many names avaliable
    int numOfVariables = rand_between(1, Indices::VARIABLE_NAMES);
    
    // The list is shuffled, so no need to check for uniquness
    vector<string> selectedNames(allNames.begin(), allNames.begin() + numOfVariables);

    // Push Variable name and Type pair into the vector
    for (const string& name : selectedNames)
    {
        string type = _tokens[Indices::VARIABLES][rand_between(0, _tokens[Indices::VARIABLES].size() - 1)];
        string value = makeValue(type);
        _variables.push_back(std::make_tuple(type, name, value));   
    }
}

Variables::Variables()
{
    _tokens = _Tokens.getTokens();
    makeNamesAndTypes();
}

// Changes value by passing in its own type
void Variables::makeNewValues(vector<tuple<string, string, string>>& tokens)
{
    for (auto&[type, name, value] : tokens)
        value = makeValue(type);
}

// Changes value by target name 
void Variables::makeNewValue(const string& target, vector<tuple<string, string, string>>& tokens)
{
    for (auto&[type, name, value] : tokens)
        if (name == target)
            value = makeValue(type);
}

// Returns int, string, or bool initializations
string Variables::makeValue(const string& type)
{
    if (type == "int")
    {
        return std::to_string(rand_between(0, 420));
    }

    // Uses index of all string inputs from tokens 
    if (type == "string")
    {
        vector<string> stringInputs = _tokens[Indices::STRING_INPUT];
        return "\"" + stringInputs[rand_between(1, stringInputs.size() - 1)] + "\"";
    }

    if (type == "bool")
    {
        return (rand_between(0, 1)) ? "True" : "False";
    }  

    return string();
}

Variables::~Variables()
{
}
