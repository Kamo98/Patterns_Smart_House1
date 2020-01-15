#include "SubSystem.h"



SubSystem::SubSystem()
{
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
