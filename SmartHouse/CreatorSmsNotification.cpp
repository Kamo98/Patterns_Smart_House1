#include "CreatorSmsNotification.h"



CreatorSmsNotification::CreatorSmsNotification()
{
	nameOfLoggers[LOG_INFO] = "SMS_Log_Info.txt";
	nameOfLoggers[LOG_WARNING] = "SMS_Log_Warning.txt";
	nameOfLoggers[LOG_ERROR] = "SMS_Log_Error.txt";
}


CreatorSmsNotification::~CreatorSmsNotification()
{
}

ISensorListener * CreatorSmsNotification::create_listener(LOG_LEVEL logLevel)
{
	if (loggers.count(logLevel) > 0)
		return loggers[logLevel];

	return loggers[logLevel] = new SmsNotification(new SensorLogger(nameOfLoggers[logLevel]));
}
