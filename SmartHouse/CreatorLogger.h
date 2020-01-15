#pragma once
#include "CreatorSensorListener.h"
#include "SensorLogger.h"

class CreatorLogger :
	public CreatorSensorListener
{
public:
	CreatorLogger();
	~CreatorLogger();

	// ������������ ����� CreatorSensorListener
	virtual ISensorListener * create_listener(LOG_LEVEL logLevel) override;
};

