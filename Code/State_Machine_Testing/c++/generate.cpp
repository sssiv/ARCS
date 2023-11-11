#include "generate.h"

Generate::Generate()
{
    _tokens = _Tokens.getTokens();
    _code = "";
};


int Generate::rand_between(const int& from, const int& to)
{
    // True Random
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

_tuple_(str, str, str) Generate::generateVariableValue(const str& type, const str& name) 
{
    // Makes first variable an int
    if (type == "int")
    {
        int randVarIndex = rand_between(0, _tokens[Columns::VARIABLE_NAMES].size() - 1);
        int randNum = rand_between(0, 420);
        return {"int", name, std::to_string(randNum) + ";"};   
    }
    
    // Makes first variable a string
    if (type == "string")
    {
        int randString = rand_between(0, _tokens[Columns::STRING_INPUT].size() - 1);
        return {"string", name, "\"" +_tokens[Columns::STRING_INPUT][randString] + "\";"};  
    }

    // Makes first variable a bool
    if (type == "bool")
    {
        int trueOfFalse = rand_between(0, 1);
        str boolValue = "";
        if (trueOfFalse) boolValue = "True;";
        else boolValue = "False;";
        return {"bool", name, boolValue};  
    }
    return {"None", "None", "None"};
}

str Generate::generateEvents()
{
    // Random variable type and event name string
    str randVarType, randEventName;

    // Int for random indecies
    int randVarIndex, randEventIndex;

    // Blank string for code
    str code = "";

    // Pick random indecies
    randVarIndex = rand_between(0, _tokens[Columns::VARIABLES].size() - 1);
    randEventIndex = rand_between(0, _tokens[Columns::EVENT_NAMES].size() - 1);

    // Pick random names from random indecies
    randVarType = _tokens[Columns::VARIABLES][randVarIndex];
    randEventName = _tokens[Columns::EVENT_NAMES][randEventIndex];

    // Save the pair of event name and its type
    _events.push_back({randEventName, randVarType});

    // Picks a random number of events to generate
    int numOfEvents = rand_between(0, _tokens[Columns::EVENT_NAMES].size() - 1);

    // Makes events
    for (int i = 0; i < numOfEvents; ++i) 
    {
        // Flag to make sure the name we pick is not repeated
        bool isUnique;

        // Loops if the randomly selected name is already chosen
        do {
            // Pick random index
            randVarIndex = rand_between(0, _tokens[Columns::VARIABLES].size() - 1);
            randEventIndex = rand_between(0, _tokens[Columns::EVENT_NAMES].size() - 1);

            // Pick random selections from list
            randVarType = _tokens[Columns::VARIABLES][randVarIndex];
            randEventName = _tokens[Columns::EVENT_NAMES][randEventIndex];

            // Put the bool initilization in here to avoid an infinite loop
            isUnique = true;

            // Itr through the events vector to find the name
            for (const auto& event : _events) 
            {
                // If the name is found
                if (event.first == randEventName) 
                {
                    // The name we chose is not unique so we set to false
                    isUnique = false;

                    // We know the name is not unique, so no point in continuing the iteration
                    break;
                }
            }
        } while (!isUnique);

        // Get event name
        _events.push_back({randEventName, randVarType});

        // Event initialization syntax
        code += "event " + _events[i].first + "{" + _events[i].second + "}\n";
    }
    return code;
}

str Generate::generateVariables()
{
    // Random variable type and event name string
    str  randVarValue;

    // Int for random indecies
    int randVarIndex = rand_between(0, _tokens[Columns::VARIABLES].size() - 1);;
    int randNameIndex = rand_between(0, _tokens[Columns::VARIABLE_NAMES].size() - 1);

    // Blank string for code
    str code = "";
    str randVarType = _tokens[Columns::VARIABLES][randVarIndex];
    str randVarName = _tokens[Columns::VARIABLE_NAMES][randNameIndex];

    _variables.push_back(generateVariableValue(randVarType, randVarName));
    // Picks a random number of events to generate
    int numOfVars = rand_between(0, _tokens[Columns::VARIABLE_NAMES].size() - 1);

    // Makes variables
    for (int i = 0; i < numOfVars; ++i) 
    {
        // Flag to make sure the name we pick is not repeated
        bool isUnique;

        // Loops if the randomly selected name is already chosen
        do {
            // Pick random index
            randVarIndex = rand_between(0, _tokens[Columns::VARIABLES].size() - 1);
            randNameIndex = rand_between(0, _tokens[Columns::VARIABLE_NAMES].size() - 1);

            // Pick random selections from list
            randVarType = _tokens[Columns::VARIABLES][randVarIndex];
            randVarName = _tokens[Columns::VARIABLE_NAMES][randNameIndex];

            // Put the bool initilization in here to avoid an infinite loop
            isUnique = true;

            // Itr through the events vector to find the name
            for (const auto& event : _events) 
            {
                // If the name is found
                if (event.first == randVarName) 
                {
                    // The name we chose is not unique so we set to false
                    isUnique = false;

                    // We know the name is not unique, so no point in continuing the iteration
                    break;
                }
            }
        } while (!isUnique);

        // Get event name
        _variables.push_back(generateVariableValue(randVarType, randVarName));

        // Event initialization syntax
        code +=  std::get<0>(_variables[i])  +  " " + std::get<1>(_variables[i]) + "= " + std::get<2>(_variables[i]) + "\n";
    }
    return code;
}

str Generate::generateActors()
{
    return _code;
}

str Generate::generateStatemachine()
{
    return _code;
}

str Generate::generateStates()
{
    return _code;
}

void Generate::generateCode(const str& filename)
{
    _code += generateEvents() + "\n";
    _code += generateVariables() + "\n";

    // Create and open a text file
    std::ofstream MyFile(filename);
    MyFile << _code;
    // Close the file
    MyFile.close();
}