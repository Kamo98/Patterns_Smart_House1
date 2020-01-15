#pragma once
#include "Appliance.h"
#include "StateDevice.h"
#include <map>
#include <string>
#include <functional>
#include "IStateAppliance.h";

using namespace std;


/*
* ����������� ����� ������ (����� ������ ProxyAppliance)
*/
class RealAppliance : public IAppliance
{
protected:
	string deviceId;			//ID ����������
	//StateDevice state;						//��������� �������
	IStateAppliance* curState;

	map<string, function<void(map<string, int>&)>> permissibleComands;	//������ ���������� ������� ������� <��� �-��, �������>

public:
	RealAppliance(string _deviceId);
	~RealAppliance();

	// ������������ ����� Appliance
	virtual void execute_command(string nameOfFunction, map<string, int> &params);

	bool has_command(string nameOfFunction);
	void exec_function(string nameOfFunction, map<string, int> &params);

	//�������
	IStateAppliance* get_state();

	//������� ��� ��������� ����������
	void turn_on();
	void turn_off();
	void block();
	void unlock();
	string get_device_id();
};
