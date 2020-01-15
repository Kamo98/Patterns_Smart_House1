#pragma once
#include "Appliance.h"
#include "Sensor.h"
#include "CreatorLogger.h"
#include "CreatorSmsNotification.h"
#include "CreatorVoiceNotification.h"

class SubSystem
{
protected:
	map<string, IAppliance*> poolAppliances;		//<ID устройства, объект устройства>
	map<string, Sensor*> poolSensors;
	CreatorSensorListener* creatorOrdinaryLogger;
	CreatorSensorListener* creatorSmsLogger;
	CreatorSensorListener* creatorVoiceLogger;
public:
	SubSystem();
	~SubSystem();
	IAppliance* request_appliance(string deviceId);		//Запросить у подсистемы прибор
	Sensor* request_sensor(string deviceId);			//Запросить у подсистемы датчик
	virtual void init() = 0;		//Каждая подсистема сама себя инициализирует
};

