#include "VoiceNotification.h"
#include <stdio.h>


VoiceNotification::VoiceNotification(ISensorListener *sub) : DecoratorSListener(sub)
{
}


VoiceNotification::~VoiceNotification()
{
}

void VoiceNotification::onIndicatorChange(Indicator * indicator)
{
	subject->onIndicatorChange(indicator);

	printf("###VOICE###\n��� ������� = %d\n", indicator->get_type_of_sensor());
	printf("����� �������� = %d\n", indicator->get_value());
	printf("######\n\n");
}
