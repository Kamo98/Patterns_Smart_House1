#pragma once
#include "IIterator.h"
#include "ExecutionSchedule.h"

class IteratorExecSchedule : public IIterator<pair<ICommands*, Trigger*>>
{
private:
	ExecutionSchedule* collection;	//Итерируемая коллекция (расписание команд и сценариев)
	int iterationState;				//Состояние итератора (индекс)
public:
	IteratorExecSchedule(ExecutionSchedule* collect);
	~IteratorExecSchedule();

	// Унаследовано через IIterator
	virtual bool has_current() override;

	// Унаследовано через IIterator
	virtual void to_next() override;

	// Унаследовано через IIterator
	virtual pair<ICommands*, Trigger*> get_cur() override;
};

