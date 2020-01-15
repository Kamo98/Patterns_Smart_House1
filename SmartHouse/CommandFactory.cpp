#include "CommandFactory.h"



CommandFlyweight * CommandFactory::getCommandFlyweight(IAppliance * appliance, string nameOfFunction)
{
	if (cache.count({ appliance, nameOfFunction }) == 0) {
		//����� ������� ����� ��������
		cache[{appliance, nameOfFunction}] = new CommandFlyweight(appliance, nameOfFunction);
	}

	return cache[{appliance, nameOfFunction}];

}
