#pragma once
#include "CreatorSensorListener.h"
#include "SmsNotification.h"
#include "SensorLogger.h"

class CreatorSmsNotification :
	public CreatorSensorListener
{
public:
	CreatorSmsNotification();
	~CreatorSmsNotification();

	// ������������ ����� CreatorSensorListener
	virtual ISensorListener * create_listener(LOG_LEVEL logLevel) override;
};

