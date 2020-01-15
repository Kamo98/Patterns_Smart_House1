#pragma once
#include "RealAppliance.h"
#include "SmartLamp.h"

//Адаптер для для умной лампы
class SmartLampAdapter : public RealAppliance
{
public:
	const static string COM_TURN_ON;
	const static string COM_TURN_OFF;
	const static string COM_SET_INTENSITY;
	const static string COM_SET_COLOR;
	const static string PARAM_INTENSITY;
	const static string PARAM_COLOR_R;
	const static string PARAM_COLOR_G;
	const static string PARAM_COLOR_B;

private:
	SmartLamp *adaptable;
public:
	SmartLampAdapter(string _deviceId, SmartLamp *_smartLamp);
	~SmartLampAdapter();

	// Унаследовано через RealAppliance
//	virtual void execute_command(string nameOfFunction, map<string, int>& params) override;
	void turn_on(map<string, int> & params);
	void turn_off(map<string, int>& params);
	void set_intensity(map<string, int>& params);
	void set_color(map<string, int>& params);
};

