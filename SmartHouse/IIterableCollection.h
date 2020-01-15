#pragma once
#include "IIterator.h"

template <typename T>
class IIterableCollection
{
public:
	virtual IIterator<T>* create_iterator() = 0;		//Создание итератора
	virtual IIterator<T>* create_iterator_comm() = 0;
};

