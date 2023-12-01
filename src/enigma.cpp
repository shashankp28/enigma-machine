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
    if (argc != 4)
    {
        cout << "Usage: ./bin/enigma <general_config_path> <input_file> <output_file>" << endl;
        return 1;
    }
    map<string, string> generalConfig = parseConfig(argv[1]);
    vector<pair<int, int>> reflectorConfig = parseReflector(generalConfig["REFLECTOR"]);
    vector<pair<int, int>> frontPanelConfig = parsePanel(generalConfig["PLUGBOARD"]);
    vector<vector<int>> rotorConfigs = parseRotors(generalConfig);
    vector<int> rotorPositions = parseRotortPositions(generalConfig["ROTOR_POSITIONS"]);

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
    ifstream inputFile(argv[2]);
    ofstream outputFile(argv[3]);
    if (!inputFile.is_open())
    {
        throw invalid_argument("Could not open input file");
    }
    string line;
    try
    {
        while (getline(inputFile, line))
        {
            string output = controller->run(line);
            outputFile << output << endl;
        }
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}