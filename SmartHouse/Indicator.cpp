#include "Indicator.h"



Indicator::Indicator(TypeOfSensor type, int val, int oldVal)
{
	typeOfSensor = type;
	value = val;
	oldValue = oldVal;
}

Indicator::~Indicator()
{
}


int Indicator::get_value()
{
	return value;
}


void Indicator::set_value(int val)
{
	oldValue = value;
	value = val;
}


TypeOfSensor Indicator::get_type_of_sensor()
{
	return typeOfSensor;
}
