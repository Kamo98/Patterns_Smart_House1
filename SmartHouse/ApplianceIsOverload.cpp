#include "ApplianceIsOverload.h"
#include "RealAppliance.h"


ApplianceIsOverload::ApplianceIsOverload()
{
}


ApplianceIsOverload::~ApplianceIsOverload()
{
}

void ApplianceIsOverload::execute_command(string nameOfFunction, map<string, int>& params, RealAppliance * app)
{
	printf("������� \"%s\" �� ����� ���� ���������. ���������� \"%s\" � ������ ������ �����������", nameOfFunction.c_str(), app->get_device_id().c_str());
}
