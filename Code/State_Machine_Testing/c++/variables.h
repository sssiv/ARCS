#include "tokens.h"
#include <utility>

class Variables
{
private:
    std::vector<std::pair<std::string, std::string>> _variables;
    int rand_between(const int&, const int&);

public:
    Variables();
    const std::vector<std::pair<std::string, std::string>>& getVariables() const {return _variables;};
    void makeNamesAndValues();
    ~Variables();
};

