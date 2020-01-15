#pragma once
#include "SensorListener.h"
#include "Sensor.h"
#include <map>
#include <vector>
//#include "ExecutionSchedule.h"
#include "IElementToVisit.h"

using namespace std;
class ExecutionSchedule;

//Предикат для сравнения показателей датчиков с требуемым значением
enum Predicate {
	MORE,		//больше
	LESS,		//меньше
	EQUAL,		//равно
	MORE_EQUAL,
	LESS_EQUAL
};


/*
* Триггер слушает список датчиков
*/
class Trigger : public ISensorListener, IElementToVisit
{
protected:
	map<TypeOfSensor, vector<int>> typeOfSensors;	//Список датчиков, на которые подписан триггер <тип датчика, список индексов>
	vector<int> requiredValues;				//Требуемые значения датчиков
	vector<Predicate> predicates;			//Предикаты для каждого показателя
	vector<bool> thisHappened;				//Событие произошло? (предикат сработал)
	bool triggerOn;							//Флаг срабатывания триггера

	int curIndex;			//Очередной индекс для typeOfSensors

	vector<ExecutionSchedule*> listnersSchedule;

public:
	Trigger();
	~Trigger();

	// Унаследовано через SensorListener
	virtual void onIndicatorChange(Indicator * indicator) override;

	bool is_trigger_on();			//Сработал ли триггер?

	//Добавить условие в триггер
	int add_condition(Sensor* sensor, int requiredValue, Predicate predicate);

	void add_listener(ExecutionSchedule* listener);
	void rem_listener(ExecutionSchedule* listener);

	vector<pair<TypeOfSensor, pair<Predicate, int>>> get_list_predicates();

	// Унаследовано через IElementToVisit
	virtual void accept(IVisitor * visitor) override;

private:	
	void switch_on();		//Вкл тригер
	void switch_off();
	//Выкл
};

