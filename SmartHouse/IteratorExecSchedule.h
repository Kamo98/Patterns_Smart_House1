#pragma once
#include "IIterator.h"
#include "ExecutionSchedule.h"

class IteratorExecSchedule : public IIterator<pair<ICommands*, Trigger*>>
{
private:
	ExecutionSchedule* collection;	//����������� ��������� (���������� ������ � ���������)
	int iterationState;				//��������� ��������� (������)
public:
	IteratorExecSchedule(ExecutionSchedule* collect);
	~IteratorExecSchedule();

	// ������������ ����� IIterator
	virtual bool has_current() override;

	// ������������ ����� IIterator
	virtual void to_next() override;

	// ������������ ����� IIterator
	virtual pair<ICommands*, Trigger*> get_cur() override;
};

