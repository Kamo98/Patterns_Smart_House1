#include "Humidifier.h"



Humidifier::Humidifier(string _deviceId) : RealAppliance(_deviceId)
{
}


Humidifier::~Humidifier()
{

}

//void Humidifier::execute_command(string nameOfFunction, map<string, int> &params)
//{
//	printf("Прибор \"%s\" выполняет команду \"%s\"\n", deviceId.c_str(), nameOfFunction.c_str());
//}
