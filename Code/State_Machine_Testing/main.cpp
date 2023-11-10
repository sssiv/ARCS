#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm> 

#define static(type, var) static_cast<type>(var)

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

class Tokens
{
public:
    vector<vector<string>> _tokens;
    void read()
    {
        ifstream file("tokens.txt");
        string line;

        while (getline(file, line))
        {
            string token;
            vector<string> v;
            istringstream iss(line);
            while (iss >> token) 
                v.push_back(token);
            _tokens.push_back(v);
        }
        file.close();
    };

    Tokens()
    {
        read();
    };
    void print()
    {
        for (const auto& vec : _tokens) {
            for (const string& token : vec) {
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
    vector<string> _events;
public:
    Generate()
    {
        _code = "";
    };

    // Generate Random Event
    string generateEvent()
    {
        // Checker to make sure the same names dont get used twice
        // RNG for how many events we want
        
        // Column index
        int VARIABLES = static(int, Columns::VARIABLES);
        int EVENT_NAMES = static(int, Columns::EVENT_NAMES);

        // Random index to check in columns
        int randVarIndex = rand_between(0, _Tokens._tokens[VARIABLES].size() - 1);
        int randEventIndex = rand_between(0, _Tokens._tokens[EVENT_NAMES].size() - 1);

        // Whats in those columns
        string randVarName = _Tokens._tokens[VARIABLES][randVarIndex];
        string randEventName = _Tokens._tokens[EVENT_NAMES][randEventIndex];

        _events.push_back(randEventName);

        // Edit the code
        string code = "event " + randEventName + "{" + randVarName + "}\n";
        return code;
    };
    ~Generate(){};
};


int main() 
{
    Tokens T;
    //T.print();

    Generate G;
    cout << G.generateEvent();
    // Create and open a text file
    ofstream MyFile("random_code_c++.txt");

    // Write to the file
    MyFile << G.generateEvent();

    // Close the file
    MyFile.close();

    return 0;
}