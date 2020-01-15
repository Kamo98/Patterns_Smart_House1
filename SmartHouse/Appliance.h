#pragma once
#include "IStateAppliance.h"
#include <string>
#include <map>
using namespace std;

class IAppliance
{
public:
	virtual void execute_command(string nameOfFunction, map<string, int> &params) = 0;
	virtual IStateAppliance* get_state() = 0;
	virtual string get_device_id() = 0;
};



