#include "WarmFloor.h"
#include <functional>

const string WarmFloor::COM_TURN_ON = "Включить подогрев";
const string WarmFloor::COM_TURN_OFF = "Отключить подогрев";
const string WarmFloor::COM_SET_INTENSITY = "Установить интенсивность подогрева";
const string WarmFloor::PARAM_INTENSITY = "intensity";


WarmFloor::WarmFloor(string _deviceId) : RealAppliance(_deviceId)
{
	permissibleComands[COM_TURN_ON] = bind(&WarmFloor::turn_on_heating, this, placeholders::_1);
	permissibleComands[COM_TURN_OFF] = bind(&WarmFloor::turn_off_heating, this, placeholders::_1);
	permissibleComands[COM_SET_INTENSITY] = bind(&WarmFloor::set_intensity, this, placeholders::_1);
	
	isHeatingOn = false;		//Подогрев изначально отключен
	intensivity = 5;			//Интенсивность подогрева по умолчанию
}


WarmFloor::~WarmFloor()
{
}

//void WarmFloor::execute_command(string nameOfFunction, map<string, int> &params)
//{
//	if (permissibleComands.count(nameOfFunction) == 0)
//		printf("Прибор \"%s\": НЕИЗВЕСТНАЯ КОМАНДА \"%s\"\n", deviceId.c_str(), nameOfFunction.c_str());
//	else {
//		permissibleComands[nameOfFunction](params);
//	}
//}


void WarmFloor::turn_on_heating(map<string, int> &params)
{
	if (!isHeatingOn) {
		printf("Прибор \"%s\": Включение подогрева у тёплого пола\n", deviceId.c_str());
		isHeatingOn = true;
	}
	else
		printf("Прибор \"%s\": Подогрев у тёплого пола УЖЕ ВКЛЮЧЕН\n", deviceId.c_str());
}


void WarmFloor::turn_off_heating(map<string, int> &params)
{
	if (isHeatingOn) {
		printf("Прибор \"%s\": Отключение подогрева у тёплого пола\n", deviceId.c_str());
		isHeatingOn = false;
	}
	else
		printf("Прибор \"%s\": Подогрев у тёплого пола ЕЩЁ НЕ ВКЛЮЧЕН\n", deviceId.c_str());
}


void WarmFloor::set_intensity(map<string, int> &params)
{
	if (!isHeatingOn) {		//Если подогрев не включен
		printf("Прибор \"%s\": Подогрев у тёплого пола ЕЩЁ НЕ ВКЛЮЧЕН\n", deviceId.c_str());
		return;
	}


	if (params.count(PARAM_INTENSITY) == 0) {
		printf("Прибор \"%s\": в команде ОТСУТСТВУЕТ ПАРАМЕТР \"%s\"\n", deviceId.c_str(), PARAM_INTENSITY);
		return;
	}


	if (params[PARAM_INTENSITY] < MIN_INTENSIVITY)
		intensivity = MIN_INTENSIVITY;
	else if (params[PARAM_INTENSITY] > MAX_INTENSIVITY)
		intensivity = MAX_INTENSIVITY;
	else
		intensivity = params[PARAM_INTENSITY];

	printf("Прибор \"%s\": новая интенсивность подогрева = %d\n", deviceId.c_str(), intensivity);
}


