#pragma once
#include "ICommands.h"


bool compare_command(ICommands *com1, ICommands *com2)
{
	return !com1 || !com2 ? 0 : com1->get_time_unix() < com2->get_time_unix();
}