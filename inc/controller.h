#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "panel.h"
#include "reflector.h"
#include "rotor.h"
class Controller
{

private:
    Rotor *rotor1;
    Rotor *rotor2;
    Rotor *rotor3;
    Reflector *reflector;
    FrontPanel *frontPanel;

public:
    Controller(Rotor *rotor1, Rotor *rotor2, Rotor *rotor3,
               Reflector *reflector, FrontPanel *frontPanel);
    char type(char input);
    string run(string input);
    void printEnigmaConfig();
};

#endif