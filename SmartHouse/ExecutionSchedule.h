#pragma once
#include "IIterableCollection.h"
#include "UserScript.h"
#include "Trigger.h"
#include "VisitorToPrintCons.h"

#include <algorithm>
#include <vector>

using namespace std;

//class Trigger;

class ExecutionSchedule : public IIterableCollection<pair<ICommands*, Trigger*>>
{

public:
	class MemontoSchedule
	{
	private:
		vector<pair<ICommands*, Trigger*>> listCommands;	//Исходный список команд или скриптов и триггеров для выполнения каждой команды
		vector<pair<ICommands*, Trigger*>> sortedListComm;	//Упорядоченный списко команд и/или скриптов (формируется в методе сортировки)

		map<Trigger*, int> countTriggerAction;				//Количество срабатываний каждого триггера
		map<Trigger*, vector<int>> trigger2index;
	public:
		MemontoSchedule(vector<pair<ICommands*, Trigger*>> &_listCommands,
			vector<pair<ICommands*, Trigger*>> &_sortedListComm,
			map<Trigger*, int> &_countTriggerAction,
			map<Trigger*, vector<int>> &_trigger2index
		);
		~MemontoSchedule();

		void restore(ExecutionSchedule* originator);

		vector<pair<ICommands*, Trigger*>> get_list_commands() const;
		/*vector<pair<ICommands*, Trigger*>> get_sorted_los_comm();
		map<Trigger*, int> get_count_trig_action();
		map<Trigger*, vector<int>> get_trigger2index();*/
	};


private:
	vector<pair<ICommands*, Trigger*>> listCommands;	//Исходный список команд или скриптов и триггеров для выполнения каждой команды
	vector<pair<ICommands*, Trigger*>> sortedListComm;	//Упорядоченный списко команд и/или скриптов (формируется в методе сортировки)

	map<Trigger*, int> countTriggerAction;				//Количество срабатываний каждого триггера
	map<Trigger*, vector<int>> trigger2index;
public:
	ExecutionSchedule();
	~ExecutionSchedule();

	// Унаследовано через IIterableCollection
	virtual IIterator<pair<ICommands*, Trigger*>>* create_iterator() override;		//Создание итератора
	virtual IIterator<pair<ICommands*, Trigger*>>* create_iterator_comm() override;

	void insert(ICommands *com, Trigger* trig);			//Вставка новго элемента в расписание

	//Геттеры
	ICommands* get_command(int i);
	Trigger* get_trigger(int i);
	void sort_list_comm_and_scripts();
	void sort_list_commands();
	void OnTriggerAction(Trigger *trig);

	void print();

	MemontoSchedule* save_state();
	//void restore_state(MemontoSchedule *st);
};

