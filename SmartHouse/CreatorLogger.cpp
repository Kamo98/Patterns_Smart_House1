#include "CreatorLogger.h"



CreatorLogger::CreatorLogger()
{
	nameOfLoggers[LOG_INFO] = "Ordinary_Log_Info.txt";
	nameOfLoggers[LOG_WARNING] = "Ordinary_Log_Warning.txt";
	nameOfLoggers[LOG_ERROR] = "Ordinary_Log_Error.txt";
}


CreatorLogger::~CreatorLogger()
{
}

ISensorListener * CreatorLogger::create_listener(LOG_LEVEL logLevel)
{
	if (loggers.count(logLevel) > 0)
		return loggers[logLevel];

	return loggers[logLevel] = new SensorLogger(nameOfLoggers[logLevel]);
}
