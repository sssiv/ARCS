#ifndef FUNC_H_
#define FUNC_H_

#include <iostream>
#include <map>

void Print();
class Vars
{
    public:
        void init();
        std::map<int, std::string> tokens;
};

#endif // FUNC_H_