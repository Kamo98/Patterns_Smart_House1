#pragma once
#include "CreatorSensorListener.h"
#include "SensorLogger.h"
#include "VoiceNotification.h"

class CreatorVoiceNotification :
	public CreatorSensorListener
{
public:
	CreatorVoiceNotification();
	~CreatorVoiceNotification();

	// Унаследовано через CreatorSensorListener
	virtual ISensorListener * create_listener(LOG_LEVEL logLevel) override;
};

