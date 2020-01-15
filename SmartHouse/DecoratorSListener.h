#pragma once
#include "SensorListener.h"
class DecoratorSListener : public ISensorListener
{
protected:
	ISensorListener *subject;
public:
	DecoratorSListener(ISensorListener *sub);
	~DecoratorSListener();

	// ������������ ����� ISensorListener
	virtual void onIndicatorChange(Indicator * indicator) = 0;
};

