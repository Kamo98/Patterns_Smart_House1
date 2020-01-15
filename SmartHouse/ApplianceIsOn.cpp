#include "ApplianceIsOn.h"
#include "RealAppliance.h"


ApplianceIsOn::ApplianceIsOn()
{
}


ApplianceIsOn::~ApplianceIsOn()
{
}

void ApplianceIsOn::execute_command(string nameOfFunction, map<string, int>& params, RealAppliance* app)
{
	if (!app->has_command(nameOfFunction))
		printf("Ïðèáîð \"%s\": ÍÅÈÇÂÅÑÒÍÀß ÊÎÌÀÍÄÀ \"%s\"\n", app->get_device_id().c_str(), nameOfFunction.c_str());
	else
		app->exec_function(nameOfFunction, params);
}
