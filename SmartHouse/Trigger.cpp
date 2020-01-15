#include "Trigger.h"
#include "ExecutionSchedule.h"


Trigger::Trigger()
{
	curIndex = 0;
	triggerOn = false;
}


Trigger::~Trigger()
{
}


//���������� callback, ���������� �� �������
void Trigger::onIndicatorChange(Indicator * indicator)
{
	TypeOfSensor type = indicator->get_type_of_sensor();
	if (typeOfSensors.count(type) > 0) {
		//��������� ��� �������, ����������� � ������� �������
		for (int i : typeOfSensors[type]) {
			bool happened;
			switch (predicates[i])
			{
				case Predicate::MORE:
					happened = indicator->get_value() > requiredValues[i];
					break;
				case Predicate::LESS:
					happened = indicator->get_value() < requiredValues[i];
					break;
				case Predicate::EQUAL:
					happened = indicator->get_value() == requiredValues[i];
					break;
				case Predicate::MORE_EQUAL:
					happened = indicator->get_value() >= requiredValues[i];
					break;
				case Predicate::LESS_EQUAL:
					happened = indicator->get_value() <= requiredValues[i];
					break;
			}
			thisHappened[i] = happened;
		}

		//���������, �� �������� �� ������

		/*vector<bool> resInsideSensor = predicate_inside_sensor();
		bool onTrigger = total_predicate(resInsideSensor);*/

		bool onTrigger = true;
		for (bool cur : thisHappened)
			onTrigger &= cur;

		if (onTrigger) {
			switch_on();	//�������� ������
			for (ExecutionSchedule* listner : listnersSchedule)
				listner->OnTriggerAction(this);
		}
		else
			switch_off();	//��������� ������
	}
	else
		printf("������! ������ ������� callback �� ����������� �������\n");
}


bool Trigger::is_trigger_on()
{
	return triggerOn;
}


int Trigger::add_condition(Sensor* sensor, int requiredValue, Predicate predicate)
{
	//�������� ������� �� ������, ���� �������� ��� ���
	if (typeOfSensors.count(sensor->get_type()) == 0)
		sensor->add_listener(this);

	//���������� ������ �������
	typeOfSensors[sensor->get_type()].push_back(curIndex++);

	//������������� ����������
	requiredValues.push_back(requiredValue);
	predicates.push_back(predicate);
	thisHappened.push_back(false);


	//������������� ������� callback ��� ����� ������� � ����� �������� ������������ �������
	onIndicatorChange(sensor->get_indicator());

	return 0;
}

void Trigger::add_listener(ExecutionSchedule * listener)
{
	listnersSchedule.push_back(listener);
}

void Trigger::rem_listener(ExecutionSchedule * listener)
{
	auto iter = find(listnersSchedule.begin(), listnersSchedule.end(), listener);
	if (iter != listnersSchedule.end())
		listnersSchedule.erase(iter);
}

vector<pair<TypeOfSensor, pair<Predicate, int>>> Trigger::get_list_predicates()
{
	vector<pair<TypeOfSensor, pair<Predicate, int>>> res;
	for (auto item : typeOfSensors)
		for (auto i : item.second)
			res.push_back({ item.first, {predicates[i], requiredValues[i]} });
	return res;
}


void Trigger::switch_on()
{
	triggerOn = true;
}


void Trigger::switch_off()
{
	triggerOn = false;
}

void Trigger::accept(IVisitor * visitor)
{
	visitor->visit(this);
}
