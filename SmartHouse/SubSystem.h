#pragma once
#include "Appliance.h"
#include "Sensor.h"
#include "CreatorLogger.h"
#include "CreatorSmsNotification.h"
#include "CreatorVoiceNotification.h"

class SubSystem
{
protected:
	map<string, IAppliance*> poolAppliances;		//<ID ����������, ������ ����������>
	map<string, Sensor*> poolSensors;
	CreatorSensorListener* creatorOrdinaryLogger;
	CreatorSensorListener* creatorSmsLogger;
	CreatorSensorListener* creatorVoiceLogger;
public:
	SubSystem();
	~SubSystem();
	IAppliance* request_appliance(string deviceId);		//��������� � ���������� ������
	Sensor* request_sensor(string deviceId);			//��������� � ���������� ������
	virtual void init() = 0;		//������ ���������� ���� ���� ��������������
};

