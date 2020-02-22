#include "ExecutionSchedule.h"



ExecutionSchedule::MemontoSchedule::MemontoSchedule(
	vector<pair<ICommands*, Trigger*>>& _listCommands, 
	vector<pair<ICommands*, Trigger*>>& _sortedListComm, 
	map<Trigger*, int>& _countTriggerAction, 
	map<Trigger*, vector<int>>& _trigger2index) 
	: 
	listCommands(_listCommands), 
	sortedListComm(_sortedListComm), 
	countTriggerAction(_countTriggerAction),
	trigger2index(_trigger2index)
{
}

ExecutionSchedule::MemontoSchedule::~MemontoSchedule()
{
}

void ExecutionSchedule::MemontoSchedule::restore(ExecutionSchedule * originator)
{
	originator->listCommands = listCommands;
	originator->sortedListComm = sortedListComm;
	originator->countTriggerAction = countTriggerAction;
	originator->trigger2index = trigger2index;
}

vector<pair<ICommands*, Trigger*>> ExecutionSchedule::MemontoSchedule::get_list_commands() const
{
	return listCommands;
}
//
//vector<pair<ICommands*, Trigger*>> ExecutionSchedule::MemontoSchedule::get_sorted_los_comm()
//{
//	return sortedListComm;
//}
//
//map<Trigger*, int> ExecutionSchedule::MemontoSchedule::get_count_trig_action()
//{
//	return countTriggerAction;
//}
//
//map<Trigger*, vector<int>> ExecutionSchedule::MemontoSchedule::get_trigger2index()
//{
//	return trigger2index;
//}
