#pragma once


//Тип сенсора
enum TypeOfSensor {
	UNDEFINED = 0,			//Неопределённый тип
	THERMOMETER = 1,		//Термометр
	HUMIDITY_METER = 2,		//Измеритель влажности
	LIGHT_METER = 4			//Измеритель освещённости
};