#pragma once
#include "StateDevice.h"
#include "TypeOfSensor.h"
#include "SensorListener.h"
#include <vector>

using namespace std;


class Sensor
{
protected:
	string deviceId;
	//StateDevice state;
	TypeOfSensor type;
	int oldValue;
	int value;
	vector<ISensorListener*> listeners;
public:
	Sensor(string _deviceId, int val);
	~Sensor();


	void add_listener(ISensorListener *listener);	//���������� ������ ���������
	void rem_listener(ISensorListener * listener);
	void set_value(int newVal);						//��������� ������ �������� ���������� �������
	int get_value();
	TypeOfSensor get_type();
	Indicator* get_indicator();			//������ ���������� �������

private:
	void notify_listners();			//���������� ����������
};

