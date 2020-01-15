#pragma once
#include "IStateAppliance.h"
class ApplianceIsOff :
	public IStateAppliance
{
public:
	ApplianceIsOff();
	~ApplianceIsOff();

	// ������������ ����� IStateAppliance
	virtual void execute_command(string nameOfFunction, map<string, int>& params, RealAppliance * app) override;
};

