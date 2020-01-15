#pragma once
#include "DecoratorSListener.h"
class VoiceNotification : public DecoratorSListener
{
public:
	VoiceNotification(ISensorListener *sub);
	~VoiceNotification();

	// ������������ ����� DecoratorSListener
	virtual void onIndicatorChange(Indicator * indicator) override;
};

