#include "events.h"

using std::vector, std::string;

Events::Events()
{
    _tokens = _Tokens.getTokens();
    makeNamesAndTypes();
}
void Events::makeNamesAndTypes()
{   
    // List of Variable types and Names
    vector<string> allNames = _tokens[Indices::EVENT_NAMES];

    // // Shuffle the list of names to randomize their order.
    std::shuffle(allNames.begin(), allNames.end(), std::default_random_engine(std::random_device()()));
    
    // How many events to randomly generate based on how many names avaliable
    int numOfEvents = rand_between(1, Indices::EVENT_NAMES);
    
    // The list is shuffled, so no need to check for uniquness
    vector<string> selectedNames(allNames.begin(), allNames.begin() + numOfEvents);

    // Push Variable name and Type pair into the vector
    for (const string& name : selectedNames)
    {
        string type = "";
        if (rand_between(0, 1))
            type = _tokens[Indices::VARIABLES][rand_between(0, _tokens[Indices::VARIABLES].size() - 1)];
        _events.push_back(std::make_pair(name, type));   
    }
}
Events::~Events()
{
}