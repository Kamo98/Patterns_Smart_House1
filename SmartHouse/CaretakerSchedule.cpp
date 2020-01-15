#include "CaretakerSchedule.h"



void CaretakerSchedule::take_memonto()
{
	history.push_back(originator->save_state());
}

void CaretakerSchedule::restore_last_memonto()
{
	if (history.size() == 0)
		return;
	history.back()->restore(originator);
	history.pop_back();
}

ExecutionSchedule * CaretakerSchedule::get_cur_schedule()
{
	return originator;
}


CaretakerSchedule::CaretakerSchedule(ExecutionSchedule * _originator)
{
	originator = _originator;
}

CaretakerSchedule::~CaretakerSchedule()
{
}
