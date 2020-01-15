#include "SmsNotification.h"
#include <stdio.h>


SmsNotification::SmsNotification(ISensorListener *sub) : DecoratorSListener(sub)
{
}


SmsNotification::~SmsNotification()
{
}

void SmsNotification::onIndicatorChange(Indicator * indicator)
{
	subject->onIndicatorChange(indicator);

	printf("***SMS***\n��� ������� = %d\n", indicator->get_type_of_sensor());
	printf("����� �������� = %d\n", indicator->get_value());
	printf("******\n\n");
}
