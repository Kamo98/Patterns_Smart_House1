#include "SmartLampAdapter.h"

const string SmartLampAdapter::COM_TURN_ON = "�������� �����";
const string SmartLampAdapter::COM_TURN_OFF = "��������� �����";
const string SmartLampAdapter::COM_SET_INTENSITY = "���������� ������������� ���������";
const string SmartLampAdapter::COM_SET_COLOR = "���������� ���� ���������";
const string SmartLampAdapter::PARAM_INTENSITY = "intensity";
const string SmartLampAdapter::PARAM_COLOR_R = "colorR";
const string SmartLampAdapter::PARAM_COLOR_G = "colorG";
const string SmartLampAdapter::PARAM_COLOR_B = "colorB";


SmartLampAdapter::SmartLampAdapter(string _deviceId, SmartLamp *_smartLamp) : RealAppliance(_deviceId)
{
	adaptable = _smartLamp;
	permissibleComands[COM_TURN_ON] = bind(&SmartLampAdapter::turn_on, this, placeholders::_1);
	permissibleComands[COM_TURN_OFF] = bind(&SmartLampAdapter::turn_off, this, placeholders::_1);
	permissibleComands[COM_SET_INTENSITY] = bind(&SmartLampAdapter::set_intensity, this, placeholders::_1);
	permissibleComands[COM_SET_COLOR] = bind(&SmartLampAdapter::set_color, this, placeholders::_1);
}


SmartLampAdapter::~SmartLampAdapter()
{
}

//void SmartLampAdapter::execute_command(string nameOfFunction, map<string, int>& params)
//{
//}


void SmartLampAdapter::turn_on(map<string, int> & params)
{
	if (adaptable->turnOn())
		printf("������ \"%s\": ��������� ����� ����� ������ �������\n", deviceId.c_str());
	else
		printf("������ \"%s\": ����� ����� ��� ��������\n", deviceId.c_str());
}


void SmartLampAdapter::turn_off(map<string, int>& params)
{
	if (adaptable->turnOff())
		printf("������ \"%s\": ���������� ����� ����� ������ �������\n", deviceId.c_str());
	else
		printf("������ \"%s\": ����� ����� �٨ �� ��������\n", deviceId.c_str());
}


void SmartLampAdapter::set_intensity(map<string, int>& params)
{
	if (params.count(PARAM_INTENSITY) == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"intensivity\" ", deviceId.c_str());
		return;
	}

	adaptable->change_intensity(params[PARAM_INTENSITY]);
	printf("������ \"%s\": ����� ������������� ����� ����� = %d\n", deviceId.c_str(), params[PARAM_INTENSITY]);
}


void SmartLampAdapter::set_color(map<string, int>& params)
{
	if (params.count(PARAM_COLOR_R) == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"%s\" ", deviceId.c_str(), PARAM_COLOR_R.c_str());
		return;
	}
	if (params.count(PARAM_COLOR_G) == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"%s\" ", deviceId.c_str(), PARAM_COLOR_G.c_str());
		return;
	}
	if (params.count(PARAM_COLOR_B) == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"%s\" ", deviceId.c_str(), PARAM_COLOR_B.c_str());
		return;
	}

	adaptable->change_color(params[PARAM_COLOR_R], params[PARAM_COLOR_G], params[PARAM_COLOR_B]);
	printf("������ \"%s\": ����� ���� ����� ����� = (%d, %d, %d)\n", deviceId.c_str(), params[PARAM_COLOR_R], params[PARAM_COLOR_G], params[PARAM_COLOR_B]);
}
