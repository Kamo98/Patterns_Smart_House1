#pragma once
#include "SensorListener.h"
#include "Sensor.h"
#include <map>
#include <vector>
//#include "ExecutionSchedule.h"
#include "IElementToVisit.h"

using namespace std;
class ExecutionSchedule;

//�������� ��� ��������� ����������� �������� � ��������� ���������
enum Predicate {
	MORE,		//������
	LESS,		//������
	EQUAL,		//�����
	MORE_EQUAL,
	LESS_EQUAL
};


/*
* ������� ������� ������ ��������
*/
class Trigger : public ISensorListener, IElementToVisit
{
protected:
	map<TypeOfSensor, vector<int>> typeOfSensors;	//������ ��������, �� ������� �������� ������� <��� �������, ������ ��������>
	vector<int> requiredValues;				//��������� �������� ��������
	vector<Predicate> predicates;			//��������� ��� ������� ����������
	vector<bool> thisHappened;				//������� ���������? (�������� ��������)
	bool triggerOn;							//���� ������������ ��������

	int curIndex;			//��������� ������ ��� typeOfSensors

	vector<ExecutionSchedule*> listnersSchedule;

public:
	Trigger();
	~Trigger();

	// ������������ ����� SensorListener
	virtual void onIndicatorChange(Indicator * indicator) override;

	bool is_trigger_on();			//�������� �� �������?

	//�������� ������� � �������
	int add_condition(Sensor* sensor, int requiredValue, Predicate predicate);

	void add_listener(ExecutionSchedule* listener);
	void rem_listener(ExecutionSchedule* listener);

	vector<pair<TypeOfSensor, pair<Predicate, int>>> get_list_predicates();

	// ������������ ����� IElementToVisit
	virtual void accept(IVisitor * visitor) override;

private:	
	void switch_on();		//��� ������
	void switch_off();
	//����
};

