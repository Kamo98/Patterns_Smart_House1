#pragma once
#include "AbstractSubSystem.h"
#include "KeysSystems.h"
#include "ClimateSystem.h"
#include "WinterSubSystem.h"
#include "SummerSystem.h"
#include "LightingSystem.h"
#include "CommPrintSchedule.h"


class Hub
{
private:
	map<KEY_SUBSYSTEM, SubSystem*> subSystems;		//<Ключ подсистемы, сама подсистема>
	map<KEY_ABSTRACT_SYS, AbstractSubSystem*> abstractSystems;		//<Ключ абстрактной подсистемы, сама подсистема>
	CommandFactory *commandFactory;
	
	const int SUMMER_TIME = 21;
	const int WINTER_TIME = 1;
	const int LEN_OF_YEAR = 40;

	static Hub* instance;
	Hub();
	~Hub();

public:
	static Hub* getInstance();
	void init();
	void OnTimerTick(int curUnixTime);

	void discharge_schedules();
	void print_schedules(KEY_SUBSYSTEM subSys, KEY_ABSTRACT_SYS abstrSys);
};

