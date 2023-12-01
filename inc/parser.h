#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;

vector<string> split(string s, string delimiter);
map<string, string> parseConfig(string file_path);
vector<pair<int, int>> parseReflector(string reflectorConf);
vector<pair<int, int>> parsePanel(string panelConf);
vector<vector<int>> parseRotors(map<string, string> &generalConfig,
                                map<string, string> &specificConfig);
vector<int> parseRotortPositions(string rotorPositions);

#endif