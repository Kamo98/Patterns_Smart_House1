#pragma once
#include "SubSystem.h"
#include "WarmFloor.h"
#include "Humidifier.h"
#include "HumidityMeter.h"
#include "Thermometer.h"

class ClimateSystem : public SubSystem
{
private:
	int countRoom;
public:
	ClimateSystem();
	~ClimateSystem();

private:
	// Унаследовано через SubSystem
	virtual void init() override;
};

