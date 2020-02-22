#include "SubSystem.h"



SubSystem::SubSystem()
{
	creatorOrdinaryLogger = nullptr;
	creatorSmsLogger = nullptr;
	creatorVoiceLogger = nullptr;
}


SubSystem::~SubSystem()
{
}


IAppliance* SubSystem::request_appliance(string deviceId)
{
	return poolAppliances[deviceId];
}


Sensor* SubSystem::request_sensor(string deviceId)
{
	return poolSensors[deviceId];
}
