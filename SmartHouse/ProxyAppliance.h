#pragma once
#include "Appliance.h"
#include "RealAppliance.h"

/*
* ������ ��� �������� ������� � ����������� �������
* ������ ����� ���� �����������, ���������������, �������������
* ���� �� ������ �������������
*/
class ProxyAppliance : public IAppliance
{
private:
	RealAppliance *subject;
	
private:
	ProxyAppliance();
	~ProxyAppliance();

	// ������������ ����� Appliance
	virtual void execute_command(string nameOfFunction, map<string, int> &params) override;
	int init_appliance(RealAppliance* realAppliance);
	// ������������ ����� IAppliance
	//virtual StateDevice get_state() override;

	// ������������ ����� IAppliance
	virtual string get_device_id() override;
	//������������� ������������� �������
};

