#pragma once
#include "Appliance.h"
#include "CommandFlyweight.h"
#include <map>
#include <string>

using namespace std;

class CommandFactory
{
	map<pair<IAppliance*, string>, CommandFlyweight*> cache;
public:

	//Получить (или создать новый) легковес
	CommandFlyweight* getCommandFlyweight(IAppliance* appliance, string nameOfFunction);
};

