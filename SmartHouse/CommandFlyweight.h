#pragma once
#include "Appliance.h"


//�������� ��� �������, �������� � ���� ����� ���� ������� (���������� � ��� �������)
class CommandFlyweight
{
private:
	IAppliance* appliance;		//����������, �������� ���������� �������
	string nameOfFunction;		//��� �������, ������� ������ ��������� ����������
public:
	CommandFlyweight(IAppliance* app, string func);
	~CommandFlyweight();
	IAppliance* get_appliance();
	string get_function();
	void execute(map<string, int> &params);
};

