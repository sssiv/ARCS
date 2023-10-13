#pragma once

#include <iostream>
using namespace std;

class LockState
{
public: 
    enum class State { LOCKED, UNLOCKED, FIRST_DIGIT_ENTERED, SECOND_DIGIT_ENTERED, THIRD_DIGIT_ENTERED, ALARM_TRIGGERED };
    
    LockState();  
    State processDigitInput(const char);
    void lock();

private:
    State currentState;
    std::string code;
    const std::string correctCode;  
};