#include "CommandFactory.h"



CommandFlyweight * CommandFactory::getCommandFlyweight(IAppliance * appliance, string nameOfFunction)
{
	if (cache.count({ appliance, nameOfFunction }) == 0) {
		//Нужно создать новый легковес
		cache[{appliance, nameOfFunction}] = new CommandFlyweight(appliance, nameOfFunction);
	}

	return cache[{appliance, nameOfFunction}];

}
