#pragma once
#include "SensorListener.h"
#include <map>
using namespace std; 

enum LOG_LEVEL {
	LOG_WARNING = 1,
	LOG_ERROR = 2,
	LOG_INFO = 4
};


class CreatorSensorListener
{
protected:
	map<LOG_LEVEL, ISensorListener*> loggers;
	map<LOG_LEVEL, string> nameOfLoggers;
public:	

	virtual ISensorListener* create_listener(LOG_LEVEL logLevel) = 0;
};

