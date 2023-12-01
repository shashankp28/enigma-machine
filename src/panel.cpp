#include <iostream>
#include <stdexcept>
#include <vector>
#include "panel.h"

using namespace std;

FrontPanel::FrontPanel(vector<pair<int, int>> panelConfig)
{
    if (panelConfig.size() != 10)
    {
        throw invalid_argument("Invalid front panel configuration");
    }
    this->frontPanelConfig = vector<int>(26, -1);

    for (int i = 0; i < 10; i++)
    {
        if (panelConfig[i].first < 0 || panelConfig[i].first > 25 ||
            panelConfig[i].second < 0 || panelConfig[i].second > 25)
        {
            throw invalid_argument("Invalid front panel configuration");
        }
        if (panelConfig[i].first == panelConfig[i].second)
        {
            throw invalid_argument("Invalid front panel configuration");
        }
        if (this->frontPanelConfig[panelConfig[i].first] != -1 ||
            this->frontPanelConfig[panelConfig[i].second] != -1)
        {
            throw invalid_argument("Invalid front panel configuration");
        }
        this->frontPanelConfig[panelConfig[i].first] = panelConfig[i].second;
        this->frontPanelConfig[panelConfig[i].second] = panelConfig[i].first;
    }
    for (int i = 0; i < 26; i++)
    {
        if (this->frontPanelConfig[i] == -1)
        {
            this->frontPanelConfig[i] = i;
        }
    }
}

int FrontPanel::getPatch(int index)
{
    if (index < 0 || index > 25)
    {
        return index;
    }
    return this->frontPanelConfig[index];
}

void FrontPanel::printFrontPanel()
{
    cout << "Front panel configuration:" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << (char)('A' + i) << " -> " << (char)('A' + this->frontPanelConfig[i]) << endl;
    }
    cout << endl;
}