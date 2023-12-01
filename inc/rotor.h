#ifndef ROTOR_H
#define ROTOR_H
#include <vector>
using namespace std;

class Rotor
{

private:
    int rotorNumber;
    int currentPosition;
    vector<int> rotorConfig;
    vector<int> reverseRotorConfig;
    int notchPosition;

public:
    Rotor(int rotorNumber, vector<int> rotorConfig);
    int getRotorNumber();
    int getCurrentPosition();
    bool isNotchPosition();
    void setCurrentPosition(int position);
    void rotateRotor();
    int getForwardMapping(int input);
    int getReverseMapping(int input);
    void printRotor();
};

#endif