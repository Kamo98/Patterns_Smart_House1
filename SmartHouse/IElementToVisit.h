#pragma once
#include "IVisitor.h"

class IElementToVisit
{
public:
	virtual void accept(IVisitor *visitor) = 0;
};

