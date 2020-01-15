#pragma once
#include <stdio.h>
#include "Hub.h"
#include "Timer.h"
#include "ICommandUI.h"


class UserInterface
{
private:
	Hub *hub;
	map<pair<KEY_SUBSYSTEM, KEY_ABSTRACT_SYS>, ICommandUI*> commPrintSchedule;
public:
	UserInterface();
	~UserInterface();

	void main_menu();
};

