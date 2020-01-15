#include "SensorLogger.h"



SensorLogger::SensorLogger(string nameOfFile)
{
	log = ofstream(nameOfFile, 'w');
}


SensorLogger::~SensorLogger()
{
	log.close();
}

void SensorLogger::onIndicatorChange(Indicator * indicator)
{
	log << "��� ������� = " << indicator->get_type_of_sensor() << "\n";
	log << "����� �������� = " << indicator->get_value() << "\n\n";
}
