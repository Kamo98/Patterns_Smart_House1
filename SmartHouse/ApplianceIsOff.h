#pragma once
#include "IStateAppliance.h"
class ApplianceIsOff :
	public IStateAppliance
{
public:
	ApplianceIsOff();
	~ApplianceIsOff();

	// Унаследовано через IStateAppliance
	virtual void execute_command(string nameOfFunction, map<string, int>& params, RealAppliance * app) override;
};

