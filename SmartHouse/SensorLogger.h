#pragma once
#include "SensorListener.h"
#include <fstream>
#include <string>
using namespace std;

//�����, ������������ ��������� ����������� ��������, �� ������� �� ��������
class SensorLogger : public ISensorListener
{
private:
	ofstream log;
public:
	SensorLogger(string nameOfFile);
	~SensorLogger();

	// ������������ ����� ISensorListener
	virtual void onIndicatorChange(Indicator * indicator) override;
};

