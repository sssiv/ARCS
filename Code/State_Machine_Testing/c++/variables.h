#include "tokens.h"
#include <utility>
#include <tuple>

class Variables
{
private:
    Tokens _Tokens;
    std::vector<std::tuple<std::string, std::string, std::string>> _variables;
    std::vector<std::vector<std::string>> _tokens;
    int rand_between(const int&, const int&);
    void makeNamesAndTypes();
    std::string makeValue(const std::string&);

public:
    Variables();
    void makeNewValues(std::vector<std::tuple<std::string, std::string, std::string>>&);
    void makeNewValue(const std::string&, std::vector<std::tuple<std::string, std::string, std::string>>&);
    const std::vector<std::tuple<std::string, std::string, std::string>>& getVariables() const {return _variables;};
    ~Variables();
};