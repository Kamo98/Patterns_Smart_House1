#pragma once
#include "ICommands.h"
#include "Appliance.h"
#include <string>
#include <map>
#include "CommandFlyweight.h"
#include "CommandFactory.h"


using namespace std;


//��������� �������
class Command : public ICommands
{
private:
	CommandFlyweight *flyweight;

	int timeUnix;				//����� ���������� �������
	map<string, int> params;	//������ ����������� ���������� �������
public:
	Command(CommandFactory *commFact, IAppliance* app, string func, int time);
	Command(Command *source);
	~Command();

	// ������������ ����� ICommands
	virtual void execute() override;
	void set_param(string idParam, int value);

	IAppliance* get_appliance();
	string get_name_of_function();
	int get_time_unix();
	map<string, int> get_params();
	

	// ������������ ����� ICommands
	//virtual string to_string() override;


	// ������������ ����� ICommands
	virtual bool is_composit() override;


	// ������������ ����� ICommands
	virtual ICommands * clone() override;


	// ������������ ����� ICommands
	virtual void accept(IVisitor * visitor) override;

};

