#include "CommandFlyweight.h"



CommandFlyweight::CommandFlyweight(IAppliance* app, string func) : appliance(app), nameOfFunction (func)
{
}


CommandFlyweight::~CommandFlyweight()
{
}


IAppliance* CommandFlyweight::get_appliance()
{
	return appliance;
}


string CommandFlyweight::get_function()
{
	return nameOfFunction;
}


void CommandFlyweight::execute(map<string, int> &params)
{
	appliance->execute_command(nameOfFunction, params);
}
