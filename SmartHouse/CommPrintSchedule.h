#pragma once
#include "ICommandUI.h"
#include "KeysSystems.h"

class Hub;

class CommPrintSchedule :
	public ICommandUI
{
private:
	KEY_SUBSYSTEM keySubSystem;
	KEY_ABSTRACT_SYS keyAbstractSystem;
	Hub *hub;
public:
	CommPrintSchedule(KEY_SUBSYSTEM subSys, KEY_ABSTRACT_SYS abstrSys, Hub* h);
	~CommPrintSchedule();

	// Унаследовано через ICommandUI
	virtual void execute() override;
};

