#pragma once
#include "Appliance.h"
#include "RealAppliance.h"

/*
* Прокси для контроля доступа к конкретному прибору
* Прибор может быть выключенным, заблокированным, перегруженным
* либо же вообще неопределённым
*/
class ProxyAppliance : public IAppliance
{
private:
	RealAppliance *subject;
	
private:
	ProxyAppliance();
	~ProxyAppliance();

	// Унаследовано через Appliance
	virtual void execute_command(string nameOfFunction, map<string, int> &params) override;
	int init_appliance(RealAppliance* realAppliance);
	// Унаследовано через IAppliance
	//virtual StateDevice get_state() override;

	// Унаследовано через IAppliance
	virtual string get_device_id() override;
	//Инициализация проксируемого объекта
};

