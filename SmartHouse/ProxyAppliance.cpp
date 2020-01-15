#include "ProxyAppliance.h"



ProxyAppliance::ProxyAppliance()
{
	subject = nullptr;
}


ProxyAppliance::~ProxyAppliance()
{
	delete subject;
	subject = nullptr;
}


void ProxyAppliance::execute_command(string nameOfFunction, map<string, int> &params)
{
	if (subject == nullptr)
		printf("������� \"%s\" �� ����� ���� ���������. ������������� ���������� �� �������\n", nameOfFunction.c_str());
	else if (subject->get_state() == StateDevice::LOCKED)
		printf("������� \"%s\" �� ����� ���� ���������. ���������� \"%s\" �������� �������������", nameOfFunction.c_str(), subject->get_device_id().c_str());
	else if (subject->get_state() == StateDevice::OVERLOAD)
		printf("������� \"%s\" �� ����� ���� ���������. ���������� \"%s\" � ������ ������ �����������", nameOfFunction.c_str(), subject->get_device_id().c_str());
	else if (subject->get_state() == StateDevice::SWITCHED_OFF)
		printf("������� \"%s\" �� ����� ���� ���������. ���������� \"%s\" � ������ ������ ���������", nameOfFunction.c_str(), subject->get_device_id().c_str());
	else
		subject->execute_command(nameOfFunction, params);
}


int ProxyAppliance::init_appliance(RealAppliance* realAppliance)
{
	subject = realAppliance;
	return 0;
}


StateDevice ProxyAppliance::get_state()
{
	return subject->get_state();
}

string ProxyAppliance::get_device_id()
{
	if (subject == nullptr) {
		printf("������������� ���������� �� �������\n");
		return "";
	}

	return subject->get_device_id();
}
