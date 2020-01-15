#include "Sensor.h"



Sensor::Sensor(string _deviceId, int val)
{
	deviceId = _deviceId;
	type = TypeOfSensor::UNDEFINED;		//Сенсор неопредленного типа
	value = val;
}


Sensor::~Sensor()
{
}


void Sensor::notify_listners()
{
	
	Indicator* indicator = get_indicator();

	//Опповещение слушателей об изменении показателя датчика
	for (ISensorListener *sl : listeners)
		sl->onIndicatorChange(indicator);
}

void Sensor::add_listener(ISensorListener *listener)
{
	listeners.push_back(listener);
}


void Sensor::rem_listener(ISensorListener * listener)
{
	auto iter = find(listeners.begin(), listeners.end(), listener);
	if (iter != listeners.end())
		listeners.erase(iter);
}

void Sensor::set_value(int newVal)
{
	oldValue = value;
	value = newVal;

	notify_listners();
}


int Sensor::get_value()
{
	return value;
}


TypeOfSensor Sensor::get_type()
{
	return type;
}

Indicator* Sensor::get_indicator()
{
	return new Indicator(type, value, oldValue);
}
