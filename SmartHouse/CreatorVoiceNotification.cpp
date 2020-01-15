#include "CreatorVoiceNotification.h"



CreatorVoiceNotification::CreatorVoiceNotification()
{
	nameOfLoggers[LOG_INFO] = "Voice_Log_Info.txt";
	nameOfLoggers[LOG_WARNING] = "Voice_Log_Warning.txt";
	nameOfLoggers[LOG_ERROR] = "Voice_Log_Error.txt";
}


CreatorVoiceNotification::~CreatorVoiceNotification()
{
}

ISensorListener * CreatorVoiceNotification::create_listener(LOG_LEVEL logLevel)
{
	if (loggers.count(logLevel) > 0)
		return loggers[logLevel];

	return loggers[logLevel] = new VoiceNotification(new SensorLogger(nameOfLoggers[logLevel]));
}
