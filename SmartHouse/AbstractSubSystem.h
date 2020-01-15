#pragma once
#include "ExecutionSchedule.h"
#include "SubSystem.h"
#include "KeysSystems.h"
#include "CommandFactory.h"
#include "CaretakerSchedule.h"

class AbstractSubSystem
{
protected:
	vector<CaretakerSchedule*> schedules;
	map<KEY_SUBSYSTEM, vector<int>> nameSys2index;
	vector<IIterator<pair<ICommands*, Trigger*>>*> iterators;
	map<KEY_SUBSYSTEM, SubSystem*> subSystems;
	CommandFactory *commandFactory;
public:
	AbstractSubSystem(CommandFactory *_commandFactory);
	~AbstractSubSystem();
	void OnTimerTick(int curUnixTime);
	void add_schedule(KEY_SUBSYSTEM subSys, ExecutionSchedule* schedule);		//ƒобавл€ет расписание в список расписаний

	virtual void buildClimateSystem() = 0;
	virtual void buildSecureSystem() = 0;
	virtual void buildLightingSystem() = 0;
	
	void add_subsystem(KEY_SUBSYSTEM key, SubSystem* subSystem);
	void discharge_iterators();

	void print_schedule(KEY_SUBSYSTEM subSys);

};

