#include "Thermometer.h"



Thermometer::Thermometer(string idDevice, int val) : Sensor(idDevice, val)
{
	type = TypeOfSensor::THERMOMETER;
}


Thermometer::~Thermometer()
{
}


