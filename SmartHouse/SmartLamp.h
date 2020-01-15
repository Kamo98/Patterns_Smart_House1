#pragma once
#include <stdio.h>

//Драйвер умной лампы, не реализующий интерфейс RealAppliance
class SmartLamp
{
private:
	int intensity;
	int colorR;
	int colorG;
	int colorB;
	bool isTurnOn;
public:
	SmartLamp();
	~SmartLamp();
	bool turnOn();			//При удачном включении возвращает true
	bool turnOff();
	void change_intensity(int newIntensity);
	void change_color(int r, int g, int b);
};

