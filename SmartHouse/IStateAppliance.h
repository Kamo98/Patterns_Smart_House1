#pragma once
#include <string>
#include <map>
using namespace std;

class RealAppliance;

class IStateAppliance
{
public:
	virtual void execute_command(string nameOfFunction, map<string, int> &params, RealAppliance* app) = 0;
};

