#pragma once
#include "Indicator.h"

class ISensorListener
{
public:
	virtual void onIndicatorChange(Indicator *indicator) = 0;
};

