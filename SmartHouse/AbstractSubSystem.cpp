#include "AbstractSubSystem.h"



AbstractSubSystem::AbstractSubSystem(CommandFactory *_commandFactory)
{
	commandFactory = _commandFactory;
}


AbstractSubSystem::~AbstractSubSystem()
{
}



void AbstractSubSystem::OnTimerTick(int curUnixTime)
{
	for (auto iter : iterators) {
		//Выполнит все команды, которые должны быть выполнены к текущему моменту времени
		while (iter->has_current() && iter->get_cur().first->get_time_unix() <= curUnixTime) {
			iter->get_cur().first->execute();
			iter->to_next();
		}
	}
}


void AbstractSubSystem::add_schedule(KEY_SUBSYSTEM subSys, ExecutionSchedule* schedule)
{
	schedules.push_back(new CaretakerSchedule(schedule));
	iterators.push_back(schedule->create_iterator_comm());
	nameSys2index[subSys].push_back(schedules.size() - 1);
}


void AbstractSubSystem::add_subsystem(KEY_SUBSYSTEM key, SubSystem* subSystem)
{
	subSystems[key] = subSystem;
}

void AbstractSubSystem::discharge_iterators()
{
	for (int i = 0; i < iterators.size(); i++) {
		delete iterators[i];
		iterators[i] = schedules[i]->get_cur_schedule()->create_iterator_comm();
	}
}

void AbstractSubSystem::print_schedule(KEY_SUBSYSTEM subSys)
{
	for (auto i : nameSys2index[subSys])
		schedules[i]->get_cur_schedule()->print();
}
