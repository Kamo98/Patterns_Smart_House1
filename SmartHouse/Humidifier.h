#pragma once
#include "RealAppliance.h"
class Humidifier : public RealAppliance
{
	const string COM_TURN_ON = "�������� ����������";
	const string COM_TURN_OFF = "��������� ����������";
	const string COM_SET_INTENSITY = "���������� ������������� ����������";

public:
	Humidifier(string _deviceId);
	~Humidifier();

	// ������������ ����� RealAppliance
//	virtual void execute_command(string nameOfFunction, map<string, int> &params) override;
};

