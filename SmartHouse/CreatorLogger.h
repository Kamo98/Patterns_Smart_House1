#pragma once
#include "CreatorSensorListener.h"
#include "SensorLogger.h"

class CreatorLogger :
	public CreatorSensorListener
{
public:
	CreatorLogger();
	~CreatorLogger();

	// Унаследовано через CreatorSensorListener
	virtual ISensorListener * create_listener(LOG_LEVEL logLevel) override;
};

