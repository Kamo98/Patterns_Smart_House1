#pragma once
#include "DecoratorSListener.h"
class SmsNotification : public DecoratorSListener
{
public:
	SmsNotification(ISensorListener *sub);
	~SmsNotification();

	// ������������ ����� DecoratorSListener
	virtual void onIndicatorChange(Indicator * indicator) override;
};

