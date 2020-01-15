#pragma once
#include "ExecutionSchedule.h"

class CaretakerSchedule
{
private:
	ExecutionSchedule *originator;
	vector<ExecutionSchedule::MemontoSchedule*> history;
public:

	void take_memonto();
	void restore_last_memonto();
	ExecutionSchedule* get_cur_schedule();

	CaretakerSchedule(ExecutionSchedule *_originator);
	~CaretakerSchedule();
};

