#include <iostream>
#include <stdexcept>
#include "panel.h"
#include "reflector.h"
#include "rotor.h"
#include "controller.h"

using namespace std;

Controller::Controller(Rotor *rotor1, Rotor *rotor2, Rotor *rotor3,
                       Reflector *reflector, FrontPanel *frontPanel)
{
    this->rotor1 = rotor1;
    this->rotor2 = rotor2;
    this->rotor3 = rotor3;
    this->reflector = reflector;
    this->frontPanel = frontPanel;
}

char Controller::type(char input)
{
    if (input <= 'A' && input >= 'Z')
    {
        return input;
    }
    int index = input - 'A';
    bool rotateRotor2 = false, rotateRotor3 = false;
    rotateRotor2 = this->rotor1->isNotchPosition();
    rotateRotor3 = rotateRotor2 && this->rotor2->isNotchPosition();
    this->rotor1->rotateRotor();
    if (rotateRotor2)
    {
        this->rotor2->rotateRotor();
    }
    if (rotateRotor3)
    {
        this->rotor3->rotateRotor();
    }
    int finalOutput = index;
    finalOutput = this->frontPanel->getPatch(finalOutput);
    finalOutput = this->rotor1->getForwardMapping(finalOutput);
    finalOutput = this->rotor2->getForwardMapping(finalOutput);
    finalOutput = this->rotor3->getForwardMapping(finalOutput);
    finalOutput = this->reflector->getReflection(finalOutput);
    finalOutput = this->rotor3->getReverseMapping(finalOutput);
    finalOutput = this->rotor2->getReverseMapping(finalOutput);
    finalOutput = this->rotor1->getReverseMapping(finalOutput);
    finalOutput = this->frontPanel->getPatch(finalOutput);
    return finalOutput + 'A';
}

string Controller::run(string input)
{
    string result = "";
    for (int i = 0; i < (int)input.length(); i++)
    {
        result += this->type(input[i]);
    }
    return result;
}

void Controller::printEnigmaConfig()
{
    cout << "Enigma Configuration:" << endl;
    cout << "Rotor 1: " << this->rotor1->getRotorNumber() << endl;
    cout << "Rotor 2: " << this->rotor2->getRotorNumber() << endl;
    cout << "Rotor 3: " << this->rotor3->getRotorNumber() << endl;
    cout << "Reflector: " << endl;
    this->reflector->printReflector();
    cout << "Front Panel: " << endl;
    this->frontPanel->printFrontPanel();
    cout << endl;
}