#pragma once
#include "RealAppliance.h"
class Humidifier : public RealAppliance
{
	const string COM_TURN_ON = "Включить увлажнение";
	const string COM_TURN_OFF = "Отключить увлажнение";
	const string COM_SET_INTENSITY = "Установить интенсивность увлажнения";

public:
	Humidifier(string _deviceId);
	~Humidifier();

	// Унаследовано через RealAppliance
//	virtual void execute_command(string nameOfFunction, map<string, int> &params) override;
};

