#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "controller.h"
#include "rotor.h"
#include "reflector.h"
#include "panel.h"
#include "parser.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: ./bin/enigma <general_config_path> <specific_config_path>" << endl;
        return 1;
    }
    map<string, string> generalConfig = parseConfig(argv[1]);
    map<string, string> specificConfig = parseConfig(argv[2]);
    vector<pair<int, int>> reflectorConfig = parseReflector(generalConfig["REFLECTOR"]);
    vector<pair<int, int>> frontPanelConfig = parsePanel(specificConfig["PLUGBOARD"]);
    vector<vector<int>> rotorConfigs = parseRotors(generalConfig, specificConfig);
    vector<int> rotorPositions = parseRotortPositions(specificConfig["ROTOR_POSITIONS"]);


    Reflector *reflector = new Reflector(reflectorConfig);
    FrontPanel *frontPanel = new FrontPanel(frontPanelConfig);
    Rotor *rotor1 = new Rotor(0, rotorConfigs[0]);
    Rotor *rotor2 = new Rotor(1, rotorConfigs[1]);
    Rotor *rotor3 = new Rotor(2, rotorConfigs[2]);
    rotor1->setCurrentPosition(rotorPositions[0]);
    rotor2->setCurrentPosition(rotorPositions[1]);
    rotor3->setCurrentPosition(rotorPositions[2]);
    Controller *controller = new Controller(rotor1, rotor2, rotor3, reflector, frontPanel);
    string input;
    while (1)
    {
        getline(cin, input);
        if (input == "--exit--")
        {
            cout << "--exit--" << endl;
            break;
        }
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        string output = controller->run(input);
        cout << output << endl;
    }
    return 0;
}