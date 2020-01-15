#include "HumidityMeter.h"



HumidityMeter::HumidityMeter(string deviceId, int val) : Sensor(deviceId, val)
{
	type = TypeOfSensor::HUMIDITY_METER;
}


HumidityMeter::~HumidityMeter()
{
}
