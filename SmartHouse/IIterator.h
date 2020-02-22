#pragma once
#include "ICommands.h"

template <typename T>
class IIterator
{
public:
	virtual T get_cur() = 0;
	virtual void to_next() = 0;			//������� � ���������� �������� ���������
	virtual bool has_current() = 0;		//���������, ���������� �� ��������� ������� ���������

	virtual ~IIterator() {}
};

