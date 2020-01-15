#pragma once
#include "Sensor.h"
class HumidityMeter : public Sensor
{
public:
	HumidityMeter(string deviceId, int val);
	~HumidityMeter();
};

