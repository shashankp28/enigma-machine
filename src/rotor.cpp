#include <iostream>
#include <stdexcept>
#include <vector>
#include "rotor.h"

using namespace std;

Rotor::Rotor(int rotorNumber, vector<int> rotorConfig)
{
    if (rotorConfig.size() != 26)
    {
        throw invalid_argument("Rotor configuration is invalid");
    }
    this->rotorConfig = vector<int>(26, -1);
    this->reverseRotorConfig = vector<int>(26, -1);
    this->rotorNumber = rotorNumber;
    this->currentPosition = 0;
    this->notchPosition = 0;
    if (notchPosition < 0 || notchPosition > 25)
    {
        throw invalid_argument("Notch position is invalid");
    }
    for (int i = 0; i < 26; i++)
    {
        if (rotorConfig[i] < 0 || rotorConfig[i] > 25)
        {
            throw invalid_argument("Rotor configuration is invalid");
        }
        if (this->rotorConfig[i] != -1)
        {
            throw invalid_argument("Rotor configuration is invalid");
        }
        this->rotorConfig[i] = rotorConfig[i];
        this->reverseRotorConfig[rotorConfig[i]] = i;
    }
}

int Rotor::getRotorNumber()
{
    return this->rotorNumber;
}

int Rotor::getCurrentPosition()
{
    return this->currentPosition;
}

bool Rotor::isNotchPosition()
{
    return this->currentPosition == this->notchPosition;
}

void Rotor::setCurrentPosition(int position)
{
    if (position < 0 || position > 25)
    {
        throw invalid_argument("Position is invalid");
    }
    this->currentPosition = position;
}

void Rotor::rotateRotor()
{
    this->currentPosition = (this->currentPosition + 1) % 26;
}

int Rotor::getForwardMapping(int input)
{
    if (input < 0 || input > 25)
    {
        return input;
    }
    int positionMathcingInput = (input + this->currentPosition) % 26;
    int output = this->rotorConfig[positionMathcingInput];
    int positionMatchingOutput = (output - this->currentPosition + 26) % 26;
    return positionMatchingOutput;
}

int Rotor::getReverseMapping(int input)
{
    if (input < 0 || input > 25)
    {
        return input;
    }
    int positionMathcingInput = (input + this->currentPosition) % 26;
    int output = this->reverseRotorConfig[positionMathcingInput];
    int positionMatchingOutput = (output - this->currentPosition + 26) % 26;
    return positionMatchingOutput;
}

void Rotor::printRotor()
{
    cout << "Rotor number: " << this->rotorNumber << endl;
    cout << "Current position: " << this->currentPosition << endl;
    cout << "Notch position: " << this->notchPosition << endl;
    cout << "Rotor configuration: \n";
    for (int i = 0; i < 26; i++)
    {
        cout << (char)(i + 'A') << " -> " << (char)(this->rotorConfig[i] + 'A') << "\n";
    }
    cout << endl;
    cout << "Reverse rotor configuration: \n";
    for (int i = 0; i < 26; i++)
    {
        cout << (char)(i + 'A') << " -> " << (char)(this->reverseRotorConfig[i] + 'A') << "\n";
    }
    cout << endl
         << endl;
}