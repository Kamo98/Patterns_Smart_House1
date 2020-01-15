#pragma once
#include "IStateAppliance.h"
class ApplianceIsOn :
	public IStateAppliance
{
public:
	ApplianceIsOn();
	~ApplianceIsOn();

	// Унаследовано через IStateAppliance
	virtual void execute_command(string nameOfFunction, map<string, int>& params, RealAppliance* app) override;
};

