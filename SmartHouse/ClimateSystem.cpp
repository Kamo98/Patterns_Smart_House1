#include "ClimateSystem.h"



ClimateSystem::ClimateSystem()
{
	countRoom = 2;

	creatorOrdinaryLogger = new CreatorLogger();
	creatorSmsLogger = new CreatorSmsNotification();
	creatorVoiceLogger = new CreatorVoiceNotification();

	init();
}


ClimateSystem::~ClimateSystem()
{
}

void ClimateSystem::init()
{
		//Инициализация приборов
	string idWarmFloor = "Тёплый пол ", idHumidifier = "Увлажнитель ";
	for (int i = 0; i < countRoom; i++) {

		string curId = idWarmFloor + to_string(i + 1);
		RealAppliance *appl = new WarmFloor(curId);
		//appl->turn_on();
		poolAppliances[curId] = appl;

		curId = idHumidifier + to_string(i + 1);
		appl = new Humidifier(curId);
		//appl->turn_on();
		poolAppliances[curId] = appl;
	}

		//Инициализация датчиков
	string idTerm = "Термометр ", idHumid = "Измеритель влажности ";

	for (int i = 0; i < countRoom; i++) {
		string curId = idTerm + to_string(i + 1);
		poolSensors[curId] = new Thermometer(curId, 15);

		poolSensors[curId]->add_listener(creatorOrdinaryLogger->create_listener(LOG_LEVEL::LOG_INFO));
		poolSensors[curId]->add_listener(creatorSmsLogger->create_listener(LOG_LEVEL::LOG_WARNING));

		curId = idHumid + to_string(i + 1);
		poolSensors[curId] = new HumidityMeter(curId, 30);

		
		poolSensors[curId]->add_listener(creatorOrdinaryLogger->create_listener(LOG_LEVEL::LOG_INFO));
		poolSensors[curId]->add_listener(creatorSmsLogger->create_listener(LOG_LEVEL::LOG_INFO));
		poolSensors[curId]->add_listener(creatorVoiceLogger->create_listener(LOG_LEVEL::LOG_ERROR));
	}

}
