#pragma once
#include "SensorListener.h"
#include <fstream>
#include <string>
using namespace std;

//Логер, записывающий изменения показателей датчиков, на которые он подписан
class SensorLogger : public ISensorListener
{
private:
	ofstream log;
public:
	SensorLogger(string nameOfFile);
	~SensorLogger();

	// Унаследовано через ISensorListener
	virtual void onIndicatorChange(Indicator * indicator) override;
};

