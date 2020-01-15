#include "WarmFloor.h"
#include <functional>

const string WarmFloor::COM_TURN_ON = "�������� ��������";
const string WarmFloor::COM_TURN_OFF = "��������� ��������";
const string WarmFloor::COM_SET_INTENSITY = "���������� ������������� ���������";
const string WarmFloor::PARAM_INTENSITY = "intensity";


WarmFloor::WarmFloor(string _deviceId) : RealAppliance(_deviceId)
{
	permissibleComands[COM_TURN_ON] = bind(&WarmFloor::turn_on_heating, this, placeholders::_1);
	permissibleComands[COM_TURN_OFF] = bind(&WarmFloor::turn_off_heating, this, placeholders::_1);
	permissibleComands[COM_SET_INTENSITY] = bind(&WarmFloor::set_intensity, this, placeholders::_1);
	
	isHeatingOn = false;		//�������� ���������� ��������
	intensivity = 5;			//������������� ��������� �� ���������
}


WarmFloor::~WarmFloor()
{
}

//void WarmFloor::execute_command(string nameOfFunction, map<string, int> &params)
//{
//	if (permissibleComands.count(nameOfFunction) == 0)
//		printf("������ \"%s\": ����������� ������� \"%s\"\n", deviceId.c_str(), nameOfFunction.c_str());
//	else {
//		permissibleComands[nameOfFunction](params);
//	}
//}


void WarmFloor::turn_on_heating(map<string, int> &params)
{
	if (!isHeatingOn) {
		printf("������ \"%s\": ��������� ��������� � ������ ����\n", deviceId.c_str());
		isHeatingOn = true;
	}
	else
		printf("������ \"%s\": �������� � ������ ���� ��� �������\n", deviceId.c_str());
}


void WarmFloor::turn_off_heating(map<string, int> &params)
{
	if (isHeatingOn) {
		printf("������ \"%s\": ���������� ��������� � ������ ����\n", deviceId.c_str());
		isHeatingOn = false;
	}
	else
		printf("������ \"%s\": �������� � ������ ���� �٨ �� �������\n", deviceId.c_str());
}


void WarmFloor::set_intensity(map<string, int> &params)
{
	if (!isHeatingOn) {		//���� �������� �� �������
		printf("������ \"%s\": �������� � ������ ���� �٨ �� �������\n", deviceId.c_str());
		return;
	}


	if (params.count(PARAM_INTENSITY) == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"%s\"\n", deviceId.c_str(), PARAM_INTENSITY);
		return;
	}


	if (params[PARAM_INTENSITY] < MIN_INTENSIVITY)
		intensivity = MIN_INTENSIVITY;
	else if (params[PARAM_INTENSITY] > MAX_INTENSIVITY)
		intensivity = MAX_INTENSIVITY;
	else
		intensivity = params[PARAM_INTENSITY];

	printf("������ \"%s\": ����� ������������� ��������� = %d\n", deviceId.c_str(), intensivity);
}


