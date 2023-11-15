#include "variables.h"

int Variables::rand_between(const int& from, const int& to)
{
    // Set Seed
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);

    // Uniform Distribution RNG
    std::uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

void Variables::makeNamesAndValues()
{
    Tokens _Tokens;
    std::vector<std::vector<std::string>> _tokens = _Tokens.getTokens();
    
    // List of Variable types and Names
    std::vector<std::string> allNames = _tokens[Indices::VARIABLE_NAMES];
    std::vector<std::string> allTypes = _tokens[Indices::VARIABLES];

    // // Shuffle the list of names to randomize their order.
    std::shuffle(allNames.begin(), allNames.end(), std::default_random_engine(std::random_device()()));
    
    // How many variables to randomly generate based on how many names avaliable
    int numOfVariables = rand_between(1, Indices::VARIABLE_NAMES);
    
    // The list is shuffled, so no need to check for uniquness
    std::vector<std::string> selectedNames(allNames.begin(), allNames.begin() + numOfVariables);

    // Push Variable name and Type pair into the vector
    for (size_t i = 0; i < selectedNames.size(); i++)
    {
        _variables.push_back(std::make_pair(selectedNames[i], allTypes[rand_between(0, allTypes.size() - 1)]));
    }
}

Variables::Variables()
{
    makeNamesAndValues();
}

Variables::~Variables()
{
}
