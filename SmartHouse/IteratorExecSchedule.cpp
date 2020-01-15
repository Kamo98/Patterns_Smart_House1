#include "IteratorExecSchedule.h"



IteratorExecSchedule::IteratorExecSchedule(ExecutionSchedule* collect)
{
	collection = collect;
	iterationState = 0;
}


IteratorExecSchedule::~IteratorExecSchedule()
{
}


bool IteratorExecSchedule::has_current()
{
	return collection->get_command(iterationState) != nullptr;
}

void IteratorExecSchedule::to_next()
{
	iterationState++;
}

pair<ICommands*, Trigger*> IteratorExecSchedule::get_cur()
{
	return { collection->get_command(iterationState), collection->get_trigger(iterationState) };
}

