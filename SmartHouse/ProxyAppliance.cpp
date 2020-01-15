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
		printf("Команда \"%s\" не может быть выполнена. Запрашиваемое устройство не создано\n", nameOfFunction.c_str());
	else if (subject->get_state() == StateDevice::LOCKED)
		printf("Команда \"%s\" не может быть выполнена. Устройство \"%s\" временно заблокировано", nameOfFunction.c_str(), subject->get_device_id().c_str());
	else if (subject->get_state() == StateDevice::OVERLOAD)
		printf("Команда \"%s\" не может быть выполнена. Устройство \"%s\" в данный момент перегружено", nameOfFunction.c_str(), subject->get_device_id().c_str());
	else if (subject->get_state() == StateDevice::SWITCHED_OFF)
		printf("Команда \"%s\" не может быть выполнена. Устройство \"%s\" в данный момент выключено", nameOfFunction.c_str(), subject->get_device_id().c_str());
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
		printf("Запрашиваемое устройство не создано\n");
		return "";
	}

	return subject->get_device_id();
}
