#include "test.h"

std::random_device rd;
std::mt19937 gen(rd());
int generateRandomNumber(int min, int max) 
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

Whitebox::Whitebox(){}

int Whitebox::successes() {return data.pass;}

int Whitebox::failures() {return data.fail;}

LockState::State Whitebox::testState(){};

/*********************************************************************************/

Blackbox::Blackbox() {}

void Blackbox::manual()
{
    LockState lock;
    LockState::State state = LockState::State::LOCKED;
    cout << "Enter a digit (0-9) to unlock the lock: ";
    while (state != LockState::State::ALARM_TRIGGERED) 
    {
        char input;
        cin >> input;

        if (input == 'q') 
            break;
        
        if (input == 'l')
        {
            lock.lock();
            cout << "Enter a digit (0-9) to unlock the lock: ";
        }

        state = lock.processDigitInput(input);

        if (state == LockState::State::ALARM_TRIGGERED) 
        {
            cout << "ALARM TRIGGERED! The lock is now inoperable." << endl;
        }
    }
}
