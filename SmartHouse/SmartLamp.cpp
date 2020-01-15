#include "SmartLamp.h"



SmartLamp::SmartLamp()
{
	//Установить параметры по умолчанию
	isTurnOn = false;
	intensity = 4;
	colorB = colorG = colorR = 255;		//Белый цвет
}


SmartLamp::~SmartLamp()
{
}


bool SmartLamp::turnOn()
{
	if (isTurnOn)
		return false;
	printf("Умная лампа успешно включена\n");
	isTurnOn = true;
	return true;
}


bool SmartLamp::turnOff()
{
	if (!isTurnOn)
		return false;
	printf("Умная лампа успешно выключена\n");
	isTurnOn = false;
	return true;
}


void SmartLamp::change_intensity(int newIntensity)
{
	intensity = newIntensity;
	printf("Новая интенсивность умной лампы = %d\n", newIntensity);
}


void SmartLamp::change_color(int r, int g, int b)
{
	colorR = r;
	colorG = g;
	colorB = b;
	printf("Новая цвет умной лампы = (%d, %d, %d)\n", colorR, colorG, colorB);
}
