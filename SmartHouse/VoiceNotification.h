#pragma once
#include "DecoratorSListener.h"
class VoiceNotification : public DecoratorSListener
{
public:
	VoiceNotification(ISensorListener *sub);
	~VoiceNotification();

	// Унаследовано через DecoratorSListener
	virtual void onIndicatorChange(Indicator * indicator) override;
};

