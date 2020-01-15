#pragma once
#include "Appliance.h"
#include "StateDevice.h"
#include <map>
#include <string>
#include <functional>
#include "IStateAppliance.h";

using namespace std;


/*
* Абстрактный класс прибор (имеет прокси ProxyAppliance)
*/
class RealAppliance : public IAppliance
{
protected:
	string deviceId;			//ID устройства
	//StateDevice state;						//Состояние прибора
	IStateAppliance* curState;

	map<string, function<void(map<string, int>&)>> permissibleComands;	//Список допустимых функций прибора <имя ф-ии, делегат>

public:
	RealAppliance(string _deviceId);
	~RealAppliance();

	// Унаследовано через Appliance
	virtual void execute_command(string nameOfFunction, map<string, int> &params);

	bool has_command(string nameOfFunction);
	void exec_function(string nameOfFunction, map<string, int> &params);

	//Геттеры
	IStateAppliance* get_state();

	//Сеттеры для состояния устройства
	void turn_on();
	void turn_off();
	void block();
	void unlock();
	string get_device_id();
};
