#pragma once
#include "RealAppliance.h"
class WarmFloor : public RealAppliance
{
public:
	const static string COM_TURN_ON;
	const static string COM_TURN_OFF;
	const static string COM_SET_INTENSITY;
	const static string PARAM_INTENSITY;

private:
	bool isHeatingOn;		//Включен ли подогрев
	int intensivity;		//Интенсивность обогрева

	const int MAX_INTENSIVITY = 10;
	const int MIN_INTENSIVITY = 1;
public:
	WarmFloor(string _deviceId);
	~WarmFloor();

	// Унаследовано через RealAppliance
//	virtual void execute_command(string nameOfFunction, map<string, int> &params) override;


private:
	void turn_on_heating(map<string, int> &params);
	void turn_off_heating(map<string, int> &params);
	void set_intensity(map<string, int> &params);
};

