#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <utility>
#include <vector>

using namespace std;

class Reflector
{

private:
    vector<int> reflectorConfig;

public:
    Reflector(vector<pair<int, int>> reflectorConfig);
    int getReflection(int index);
    void printReflector();
};

#endif