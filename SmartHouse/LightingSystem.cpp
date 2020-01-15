#include "LightingSystem.h"



LightingSystem::LightingSystem()
{
	countLamp = 3;
	init();
}

LightingSystem::LightingSystem(int _countLamp)
{
	countLamp = _countLamp;

	init();
}


LightingSystem::~LightingSystem()
{
}

void LightingSystem::init()
{

	//Инициализация ламп
	string idLamp = "Адаптер умной лампы ";
	for (int i = 0; i < countLamp; i++) {
		string curId = idLamp + to_string(i+1);
		RealAppliance *appl = new SmartLampAdapter(curId, new SmartLamp());
		appl->turn_on();
		poolAppliances[curId] = appl;
	}
}
