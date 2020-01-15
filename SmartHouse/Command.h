#pragma once
#include "ICommands.h"
#include "Appliance.h"
#include <string>
#include <map>
#include "CommandFlyweight.h"
#include "CommandFactory.h"


using namespace std;


//ќтдельна€ команда
class Command : public ICommands
{
private:
	CommandFlyweight *flyweight;

	int timeUnix;				//¬рем€ выполнени€ команды
	map<string, int> params;	//—писок именованных параметров функции
public:
	Command(CommandFactory *commFact, IAppliance* app, string func, int time);
	Command(Command *source);
	~Command();

	// ”наследовано через ICommands
	virtual void execute() override;
	void set_param(string idParam, int value);

	IAppliance* get_appliance();
	string get_name_of_function();
	int get_time_unix();
	map<string, int> get_params();
	

	// ”наследовано через ICommands
	//virtual string to_string() override;


	// ”наследовано через ICommands
	virtual bool is_composit() override;


	// ”наследовано через ICommands
	virtual ICommands * clone() override;


	// ”наследовано через ICommands
	virtual void accept(IVisitor * visitor) override;

};

