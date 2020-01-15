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
	printf("������� \"%s\" �� ����� ���� ���������. ���������� \"%s\" � ������ ������ ���������", nameOfFunction.c_str(), app->get_device_id().c_str());
}
