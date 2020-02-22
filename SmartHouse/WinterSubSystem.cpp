#include "WinterSubSystem.h"
#include "CaretakerSchedule.h"


WinterSubSystem::WinterSubSystem(CommandFactory *_commandFactory) : AbstractSubSystem(_commandFactory)
{
}


WinterSubSystem::~WinterSubSystem()
{
}

void WinterSubSystem::buildClimateSystem()
{
	/*
	* Создать команды и скрипты для устройств
	*/
	if (subSystems.count(KEY_SUBSYSTEM::Climate_System) == 0) {
		printf("ОШИБКА! Климатическая подсистема не инициализирована");
		return;
	}
	SubSystem *climate = subSystems[KEY_SUBSYSTEM::Climate_System];

	WarmFloor* warmFloor1 = (WarmFloor*)climate->request_appliance("Тёплый пол 1");
	WarmFloor* warmFloor2 = (WarmFloor*)climate->request_appliance("Тёплый пол 2");
	IAppliance* hum1 = climate->request_appliance("Увлажнитель 1");

	Command *com1 = new Command(commandFactory, warmFloor1, WarmFloor::COM_TURN_ON, 3);
	Command *com2 = new Command(commandFactory, warmFloor1, WarmFloor::COM_TURN_ON, 5);
	Command *com3 = new Command(commandFactory, warmFloor2, WarmFloor::COM_TURN_ON, 8);
	Command *com4 = new Command(commandFactory, warmFloor1, WarmFloor::COM_TURN_OFF, 10);
	Command *com5 = new Command(commandFactory, warmFloor2, WarmFloor::COM_TURN_OFF, 12);
	Command *com6 = new Command(commandFactory, hum1, "Test command 2", 13);
	Command *com7 = new Command(commandFactory, hum1, "Test command 3", 14);

	Command *com8 = new Command(commandFactory, warmFloor1, WarmFloor::COM_TURN_ON, 16);
	Command *com9 = new Command(commandFactory, warmFloor1, WarmFloor::COM_SET_INTENSITY, 17);
	com9->set_param(WarmFloor::PARAM_INTENSITY, 8);


	//Создать сценарии
	UserScript *script1 = new UserScript();
	script1->add(com1);
	script1->add(com2);
	script1->add(com3);

	UserScript *script2 = new UserScript();
	script2->add(com4);
	script2->add(com5);

	UserScript *script2Copy = (UserScript*)script2->clone();
	script2Copy->add(new Command(commandFactory, warmFloor2, WarmFloor::COM_TURN_ON, 11));
	/*********************/


	//Создать расписание выполнения команд и сценариев
	ExecutionSchedule *schedule = new ExecutionSchedule();

	schedule->insert(script2, nullptr);


	schedule->insert(script1, nullptr);
	schedule->insert(com6, nullptr);
	schedule->insert(com7, nullptr);


	schedule->insert(com8, nullptr);
	schedule->insert(com9, nullptr);
	schedule->insert(script2Copy, nullptr);


	add_schedule(KEY_SUBSYSTEM::Climate_System, schedule);
}

void WinterSubSystem::buildSecureSystem()
{
}

void WinterSubSystem::buildLightingSystem()
{
	if (subSystems.count(KEY_SUBSYSTEM::Lighting_System) == 0) {
		printf("ОШИБКА! Осветительная подсистема не инициализирована");
		return;
	}
	SubSystem *lightingSystem = subSystems[KEY_SUBSYSTEM::Lighting_System];

	
	SmartLampAdapter* smartLamp1 = (SmartLampAdapter*)lightingSystem->request_appliance("Адаптер умной лампы 1");
	SmartLampAdapter* smartLamp2 = (SmartLampAdapter*)lightingSystem->request_appliance("Адаптер умной лампы 2");

	Command *com1 = new Command(commandFactory, smartLamp1, SmartLampAdapter::COM_TURN_ON, 6);
	Command *com2 = new Command(commandFactory, smartLamp2, SmartLampAdapter::COM_TURN_ON, 9);
	Command *com3 = new Command(commandFactory, smartLamp2, SmartLampAdapter::COM_SET_COLOR, 9);
	com3->set_param(SmartLampAdapter::PARAM_COLOR_R, 255);
	com3->set_param(SmartLampAdapter::PARAM_COLOR_G, 105);
	com3->set_param(SmartLampAdapter::PARAM_COLOR_B, 90);
	Command *com3Copy = (Command*)com3->clone();
	com3Copy->set_param(SmartLampAdapter::PARAM_COLOR_R, 66);
	 
	Command *com31 = new Command(commandFactory, smartLamp1, SmartLampAdapter::COM_TURN_OFF, 15);
	Command *com4 = new Command(commandFactory, smartLamp2, SmartLampAdapter::COM_TURN_OFF, 20);
	Command *com5 = new Command(commandFactory, smartLamp1, SmartLampAdapter::COM_SET_INTENSITY, 7);
	com5->set_param(SmartLampAdapter::PARAM_INTENSITY, 20);


	//Создать сценарии
	UserScript *scriptLamp1 = new UserScript();
	scriptLamp1->add(com1);
	scriptLamp1->add(com31);
	scriptLamp1->add(com5);

	UserScript *scriptLamp2 = new UserScript();
	scriptLamp2->add(com2);
	scriptLamp2->add(com3);
	scriptLamp2->add(com4);
	scriptLamp2->add(com3Copy);
	/*********************/

	//Создать расписание выполнения команд и сценариев
	ExecutionSchedule *schedule = new ExecutionSchedule();

	schedule->insert(scriptLamp1, nullptr);
	schedule->insert(scriptLamp2, nullptr);

	add_schedule(KEY_SUBSYSTEM::Lighting_System, schedule);

}
