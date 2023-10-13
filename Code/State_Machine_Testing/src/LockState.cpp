#include "LockState.h"

LockState::LockState() : currentState(State::LOCKED), code(""), correctCode("123") {}

LockState::State LockState::processDigitInput(const char digit) 
{
    switch (currentState) 
    {
        case State::LOCKED:
            if (isdigit(digit)) 
            {
                code += digit;
                currentState = State::FIRST_DIGIT_ENTERED;
            }
            break;

        case State::FIRST_DIGIT_ENTERED:
            if (isdigit(digit)) 
            {
                code += digit;
                currentState = State::SECOND_DIGIT_ENTERED;
            }
            break;

        case State::SECOND_DIGIT_ENTERED:
            if (isdigit(digit)) 
            {
                code += digit;
                currentState = State::THIRD_DIGIT_ENTERED;
            }
            if (currentState == State::THIRD_DIGIT_ENTERED)
            {
                if (code == correctCode) 
                {
                    currentState = State::UNLOCKED;
                    cout << "Lock is now UNLOCKED." << endl;
                    cout << "enter l to re-lock" << endl;
                } 
                else 
                {
                    cout << "Incorrect code. Lock remains LOCKED." << endl;
                    currentState = State::ALARM_TRIGGERED;
                }
            }
            break;
    }
    return currentState;
}

void LockState::lock() 
{
    code = "";
    currentState = State::LOCKED;
}