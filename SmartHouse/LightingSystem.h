#pragma once
#include "SubSystem.h"
#include "SmartLamp.h"
#include "SmartLampAdapter.h"

class LightingSystem : public SubSystem
{
private:
	int countLamp;
public:
	LightingSystem();
	LightingSystem(int _countLamp);
	~LightingSystem();

	// Унаследовано через SubSystem
	virtual void init() override;
};

