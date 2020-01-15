#pragma once
#include "TypeOfSensor.h"

class Indicator
{
private:
	TypeOfSensor typeOfSensor;
	int value;
	int oldValue;
public:
	Indicator(TypeOfSensor type, int val, int oldVal);
	~Indicator();


	int get_value();
	void set_value(int val);
	TypeOfSensor get_type_of_sensor();
};

