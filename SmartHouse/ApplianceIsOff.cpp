#include "ApplianceIsOff.h"
#include "RealAppliance.h"


ApplianceIsOff::ApplianceIsOff()
{
}


ApplianceIsOff::~ApplianceIsOff()
{
}

void ApplianceIsOff::execute_command(string nameOfFunction, map<string, int>& params, RealAppliance * app)
{
	printf("Команда \"%s\" не может быть выполнена. Устройство \"%s\" в данный момент выключено", nameOfFunction.c_str(), app->get_device_id().c_str());
}
