#include "CommPrintSchedule.h"
#include "Hub.h"



CommPrintSchedule::CommPrintSchedule(KEY_SUBSYSTEM subSys, KEY_ABSTRACT_SYS abstrSys, Hub* h)
{
	keySubSystem = subSys;
	keyAbstractSystem = abstrSys;
	hub = h;
}


CommPrintSchedule::~CommPrintSchedule()
{
}

void CommPrintSchedule::execute()
{
	hub->print_schedules(keySubSystem, keyAbstractSystem);
}
