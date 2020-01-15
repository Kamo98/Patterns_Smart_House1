#include "Command.h"



Command::Command(CommandFactory *commFact, IAppliance* app, string func, int time)
{
	timeUnix = time;
	flyweight = commFact->getCommandFlyweight(app, func);
}

Command::Command(Command *source) {
	flyweight = source->flyweight;
	timeUnix = source->timeUnix;
	params = source->params;
}

Command::~Command()
{
}


void Command::execute()
{
	flyweight->execute(params);
}


IAppliance * Command::get_appliance()
{
	return flyweight->get_appliance();
}

string Command::get_name_of_function()
{
	return flyweight->get_function();
}


void Command::set_param(string idParam, int value)
{
	params[idParam] = value;
}



int Command::get_time_unix()
{
	return timeUnix;
}

map<string, int> Command::get_params()
{
	return params;
}

//string Command::to_string()
//{
//	char buf[20];
//	itoa(timeUnix, buf, 10);
//	string s = string(buf) + " : " + flyweight->get_appliance()->get_device_id() + "->" + flyweight->get_function() + "(";
//	for (auto param : params) {
//		itoa(param.second, buf, 10);
//		s += ", [\"" + param.first + "\"] = " + string(buf);
//	}
//	s += ")";
//	return s;
//}

bool Command::is_composit()
{
	return false;
}

ICommands * Command::clone()
{
	return new Command(this);
}

void Command::accept(IVisitor * visitor)
{
	visitor->visit(this);
}
