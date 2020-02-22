#pragma once
#include "ICommands.h"

template <typename T>
class IIterator
{
public:
	virtual T get_cur() = 0;
	virtual void to_next() = 0;			//Перейти к следующему элементу коллекции
	virtual bool has_current() = 0;		//Проверить, существует ли следующий элемент коллекции

	virtual ~IIterator() {}
};

