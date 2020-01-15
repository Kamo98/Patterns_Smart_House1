#pragma once
#include "Sensor.h"
class Thermometer : public Sensor
{
public:
	Thermometer(string idDevice, int val);
	~Thermometer();
};

