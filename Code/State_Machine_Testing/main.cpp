// basic IO
#include <iostream>

// File handler libraries
#include <fstream>
#include <sstream>

// Used for rng
#include <random>
#include <chrono>

// Vector, obviously
#include <vector>

// I got annoyed typing the entire thing out to cast enums
#define static(type, var) static_cast<type>(var)

// One of the few times in life ill ever use this
using namespace std;

// Generates a random number starting "From" X all the way "to" Y
int rand_between(const int& from, const int& to)
{
    // True Random
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

// For making 2D vectors easier to read. These are all the columns
enum class Columns 
{
    TYPES, 
    NUMBERS, 
    BRACKETS, 
    KEYWORDS, 
    VARIABLES, 
    OPERATORS, 
    PUNCTUATION, 
    ACTOR_NAMES, 
    STATE_NAMES, 
    VARIABLE_NAMES, 
    EVENT_NAMES
};

// Token handler
class Tokens
{
public:
    vector<vector<string>> _tokens;

    // Get tokens given to us from the Python script
    void read()
    {
        // Token text file made from python
        ifstream file("tokens.txt");

        // Used to read in each line
        string line;

        // From file, input line
        while (getline(file, line))
        {
            // Used for individual tokens
            string token;

            // Temp vector for making a vector for the 2D vector
            vector<string> v;

            // Set iss to read in from line variable
            istringstream iss(line);

            // Continue reading while there is a toke in that line
            while (iss >> token) 
                // Save what we read in
                v.push_back(token);

            // Push new line into the 2D vector
            _tokens.push_back(v);
        }

        // Close file
        file.close();
    };

    Tokens()
    {
        // Get tokens from pythons text file
        read();
    };

    // Print function to confirm we got all the tokens
    void print()
    {
        // For a vector iterating through the 2D vector
        for (const auto& vec : _tokens) 
        {
            // For a string iterating through the vector thats looking at an individual column
            for (const string& token : vec) 
            {
                // Show the token
                cout << token << " ";
            }
            cout << endl;
        }
    }
    ~Tokens(){};
};


class Generate
{
private:
    string _code;
    Tokens _Tokens;
    vector<pair<string, string>> _events;
    
public:
    Generate()
    {
        _code = "";
    };

    // Generate Random Event
    string generateEvent() 
    {
        // Get column indecies for better readbility
        int VARIABLES = static_cast<int>(Columns::VARIABLES);
        int EVENT_NAMES = static_cast<int>(Columns::EVENT_NAMES);

        // Random variable type and event name string
        string randVarType, randEventName;

        // Int for random indecies
        int randVarIndex, randEventIndex;

        // Blank string for code
        string code = "";

        // Pick random indecies
        randVarIndex = rand_between(0, _Tokens._tokens[VARIABLES].size() - 1);
        randEventIndex = rand_between(0, _Tokens._tokens[EVENT_NAMES].size() - 1);

        // Pick random names from random indecies
        randVarType = _Tokens._tokens[VARIABLES][randVarIndex];
        randEventName = _Tokens._tokens[EVENT_NAMES][randEventIndex];

        // Save the pair of event name and its type
        _events.push_back({randEventName, randVarType});

        // Picks a random number of events to generate
        int numOfEvents = rand_between(1, _Tokens._tokens[EVENT_NAMES].size() - 1);

        // Makes events
        for (int i = 0; i < numOfEvents; ++i) 
        {
            // Flag to make sure the name we pick is not repeated
            bool isUnique;

            // Loops if the randomly selected name is already chosen
            do {
                // Pick random index
                randVarIndex = rand_between(0, _Tokens._tokens[VARIABLES].size() - 1);
                randEventIndex = rand_between(0, _Tokens._tokens[EVENT_NAMES].size() - 1);

                // Pick random selections from list
                randVarType = _Tokens._tokens[VARIABLES][randVarIndex];
                randEventName = _Tokens._tokens[EVENT_NAMES][randEventIndex];

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
    
    // Actor Code
    string generateActor()
    {
        return _code;
    }

    // Statemachine Code
    string generateStatemachine()
    {
        return _code;
    }

    // States Code
    string generateStates()
    {
        return _code;
    }

    // Generates a new text file with proteus code
    void generateCode(string fileName)
    {
        _code += generateEvent();

        // Create and open a text file
        ofstream MyFile(fileName);
        MyFile << _code;
        // Close the file
        MyFile.close();
    }

    ~Generate(){};
};


int main() 
{
    Tokens T;

    Generate G;
    G.generateCode("random_code_c++.txt");
    return 0;
}