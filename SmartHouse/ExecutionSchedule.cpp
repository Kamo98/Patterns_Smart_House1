#include "ExecutionSchedule.h"
#include "IteratorExecSchedule.h"

ExecutionSchedule::ExecutionSchedule()
{
}


ExecutionSchedule::~ExecutionSchedule()
{
}


IIterator<pair<ICommands*, Trigger*>>* ExecutionSchedule::create_iterator()
{
		//Сортировка команд и сценаривев внутри расписания
	this->sort_list_comm_and_scripts();
	return new IteratorExecSchedule(this);
}

IIterator<pair<ICommands*, Trigger*>>* ExecutionSchedule::create_iterator_comm()
{
	//Сортировка команд и сценаривев внутри расписания
	this->sort_list_commands();
	return new IteratorExecSchedule(this);
}


void ExecutionSchedule::insert(ICommands *com, Trigger* trig)
{
	listCommands.push_back({ com, trig });
	if (trig != nullptr) {
		trigger2index[trig].push_back(listCommands.size() - 1);
		countTriggerAction[trig] = 0;
		trig->add_listener(this);
	}
}


ICommands * ExecutionSchedule::get_command(int i)
{
	if (i < sortedListComm.size())
		return sortedListComm[i].first;
	else
		return nullptr;
}


Trigger* ExecutionSchedule::get_trigger(int i)
{
	if (i < sortedListComm.size())
		return sortedListComm[i].second;
	else
		return nullptr;
}


bool compare_comm_trig(pair<ICommands*, Trigger*> o1, pair<ICommands*, Trigger*> o2)
{
	return o1.first->get_time_unix() < o2.first->get_time_unix();
}


void ExecutionSchedule::sort_list_comm_and_scripts()
{
	sortedListComm = listCommands;
	sort(sortedListComm.begin(), sortedListComm.end(), compare_comm_trig);
}



void ExecutionSchedule::sort_list_commands()
{
	sortedListComm.clear();
	for (auto item : listCommands)
		if (item.first->is_composit()) {		//Это композит?
			Trigger* trig = item.second;
			vector<ICommands*> commsInScript = ((UserScript*)item.first)->get_array_commands();

			for (auto comm : commsInScript) {
				sortedListComm.push_back({ comm, trig });
			}
		}
		else
			sortedListComm.push_back(item);
	sort(sortedListComm.begin(), sortedListComm.end(), compare_comm_trig);
}


void ExecutionSchedule::OnTriggerAction(Trigger *trig)
{
	for (auto i : trigger2index[trig])
		listCommands[i].first->execute();
	countTriggerAction[trig]++;
}

void ExecutionSchedule::print()
{
	IIterator<pair<ICommands*, Trigger*>> *iter1 = create_iterator();

	VisitorToPrintCons *visitor = new VisitorToPrintCons();

	while (iter1->has_current()) {
		printf("\n\n==========================\n\n");
		//printf("%s", iter1->get_cur().first->to_string().c_str());
		IElementToVisit* elem = (IElementToVisit*)iter1->get_cur().first;
		elem->accept(visitor);
		if (iter1->get_cur().second != nullptr)
			iter1->get_cur().second->accept(visitor);
		iter1->to_next();
	}

}

ExecutionSchedule::MemontoSchedule* ExecutionSchedule::save_state()
{
	return new MemontoSchedule(listCommands, sortedListComm, countTriggerAction, trigger2index);
}

//void ExecutionSchedule::restore_state(ExecutionSchedule::MemontoSchedule * st)
//{
//	listCommands = st->get_list_commands();
//	sortedListComm = st->get_sorted_los_comm();
//	countTriggerAction = st->get_count_trig_action();
//	trigger2index = st->get_trigger2index();
//}
