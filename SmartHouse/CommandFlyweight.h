#pragma once
#include "Appliance.h"


//Легковес для команды, содержит в себе общие поля команды (устройство и имя функции)
class CommandFlyweight
{
private:
	IAppliance* appliance;		//Устройство, которому адресована команда
	string nameOfFunction;		//Имя функции, которую должно выполнить устройство
public:
	CommandFlyweight(IAppliance* app, string func);
	~CommandFlyweight();
	IAppliance* get_appliance();
	string get_function();
	void execute(map<string, int> &params);
};

