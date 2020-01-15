#include "RealAppliance.h"
#include "ApplianceIsOff.h"
#include "ApplianceIsOn.h"
#include "ApplianceIsOverload.h"


RealAppliance::RealAppliance(string _deviceId)
{
	deviceId = _deviceId;
	//state = StateDevice::SWITCHED_OFF;
	curState = new ApplianceIsOff();
}


RealAppliance::~RealAppliance()
{
}

void RealAppliance::execute_command(string nameOfFunction, map<string, int>& params)
{
	/*if (state == StateDevice::LOCKED)
		printf("Команда \"%s\" не может быть выполнена. Устройство \"%s\" временно заблокировано", nameOfFunction.c_str(), get_device_id().c_str());
	else if (state == StateDevice::OVERLOAD)
		printf("Команда \"%s\" не может быть выполнена. Устройство \"%s\" в данный момент перегружено", nameOfFunction.c_str(), get_device_id().c_str());
	else if (state == StateDevice::SWITCHED_OFF)
		printf("Команда \"%s\" не может быть выполнена. Устройство \"%s\" в данный момент выключено", nameOfFunction.c_str(), get_device_id().c_str());
	else if (permissibleComands.count(nameOfFunction) == 0)
		printf("Прибор \"%s\": НЕИЗВЕСТНАЯ КОМАНДА \"%s\"\n", deviceId.c_str(), nameOfFunction.c_str());
	else
		permissibleComands[nameOfFunction](params);*/

	curState->execute_command(nameOfFunction, params, this);
}

bool RealAppliance::has_command(string nameOfFunction)
{
	return permissibleComands.count(nameOfFunction) != 0;
}

void RealAppliance::exec_function(string nameOfFunction, map<string, int>& params)
{
	permissibleComands[nameOfFunction](params);
}


//void RealAppliance::execute_command(string nameOfFunction)
//{
//	printf("Выполнение команды %s реальным прибором\n", nameOfFunction);
//}


IStateAppliance* RealAppliance::get_state()
{
	return curState;
}


void RealAppliance::turn_on()
{
	//state = StateDevice::SWITCHED_ON;
	delete curState;
	curState = new ApplianceIsOn();
}


void RealAppliance::turn_off()
{
	//state = StateDevice::SWITCHED_OFF;
	delete curState;
	curState = new ApplianceIsOff();
}


//void RealAppliance::block()
//{
//	state = StateDevice::LOCKED;
//}
//
//
//void RealAppliance::unlock()
//{
//	state = StateDevice::SWITCHED_ON;
//}


string RealAppliance::get_device_id()
{
	return deviceId;
}
