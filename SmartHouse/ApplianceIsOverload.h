#pragma once
#include "IStateAppliance.h"
class ApplianceIsOverload :
	public IStateAppliance
{
public:
	ApplianceIsOverload();
	~ApplianceIsOverload();

	// ������������ ����� IStateAppliance
	virtual void execute_command(string nameOfFunction, map<string, int>& params, RealAppliance * app) override;
};

