#ifndef FRONT_PANEL_H
#define FRONT_PANEL_H
#include <utility>
#include <vector>

using namespace std;

class FrontPanel
{

private:
    vector<int> frontPanelConfig;
    vector<int> reverseFrontPanelConfig;

public:
    FrontPanel(vector<pair<int, int>> frontPanelConfig);
    int getPatch(int index);
    void printFrontPanel();
};

#endif