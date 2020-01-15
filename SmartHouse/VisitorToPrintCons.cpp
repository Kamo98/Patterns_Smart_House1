#include "VisitorToPrintCons.h"
#include "Command.h"
#include "UserScript.h"
#include "Trigger.h"


VisitorToPrintCons::VisitorToPrintCons()
{
	countTabs = 0;
	sensor2string[TypeOfSensor::HUMIDITY_METER] = "Влажность";
	sensor2string[TypeOfSensor::LIGHT_METER] = "Освещнность";
	sensor2string[TypeOfSensor::THERMOMETER] = "Температура";

	predicate2string[Predicate::EQUAL] = "==";
	predicate2string[Predicate::LESS] = "<";
	predicate2string[Predicate::LESS_EQUAL] = "<=";
	predicate2string[Predicate::MORE] = ">";
	predicate2string[Predicate::MORE_EQUAL] = ">=";
}


VisitorToPrintCons::~VisitorToPrintCons()
{
}

void VisitorToPrintCons::visit(Command * com)
{
	string paramsS;
	map<string, int> params = com->get_params();
	for (auto param : params) {
		char buf[20];
		itoa(param.second, buf, 10);
		paramsS += ", [\"" + param.first + "\"] = " + string(buf);
	}

	for (int i = 0; i < countTabs; i++)
		printf("\t");
	printf("%d: %s->%s(%s)\n", com->get_time_unix(), 
			com->get_appliance()->get_device_id().c_str(), 
				com->get_name_of_function().c_str(), 
					paramsS.c_str());
}

void VisitorToPrintCons::visit(UserScript * script)
{
	for (int i = 0; i < countTabs; i++)
		printf("\t");
	printf("Script:\n");

	vector<ICommands*> commands = script->get_children();

	countTabs++;
	for (auto com : commands)
		com->accept(this);
	countTabs--;
}

void VisitorToPrintCons::visit(Trigger * trigg)
{
	for (int i = 0; i < countTabs; i++)
		printf("\t");
	printf("Triggers:\n{\n");
	vector<pair<TypeOfSensor, pair<Predicate, int>>> list = trigg->get_list_predicates();
	for (auto item : list)
		printf("%s %s %d;\n", sensor2string[item.first].c_str(), predicate2string[item.second.first].c_str(), item.second.second);

	printf("\n}\n");
}
