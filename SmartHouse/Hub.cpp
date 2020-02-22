#include "Hub.h"


Hub* Hub::instance = nullptr;

Hub::Hub()
{
	commandFactory = new CommandFactory();
}


Hub::~Hub()
{
	delete commandFactory;
}


Hub * Hub::getInstance()
{
	if (instance == nullptr)
		instance = new Hub();
	return instance;
}

void Hub::init()
{
	AbstractSubSystem *winter = new WinterSubSystem(commandFactory);
	AbstractSubSystem *summer = new SummerSystem(commandFactory);
	abstractSystems[KEY_ABSTRACT_SYS::Winter_System] = winter;
	abstractSystems[KEY_ABSTRACT_SYS::Summer_System] = summer;

	SubSystem *climate = new ClimateSystem();
	subSystems[KEY_SUBSYSTEM::Climate_System] = climate;
	winter->add_subsystem(KEY_SUBSYSTEM::Climate_System, climate);
	summer->add_subsystem(KEY_SUBSYSTEM::Climate_System, climate);

	winter->buildClimateSystem();
	summer->buildClimateSystem();


	SubSystem *lighting = new LightingSystem();
	subSystems[KEY_SUBSYSTEM::Lighting_System] = lighting;
	winter->add_subsystem(KEY_SUBSYSTEM::Lighting_System, lighting);
	summer->add_subsystem(KEY_SUBSYSTEM::Lighting_System, lighting);

	winter->buildLightingSystem();
	summer->buildLightingSystem();
}


void Hub::OnTimerTick(int curUnixTime)
{
	if (curUnixTime % LEN_OF_YEAR == SUMMER_TIME)
		printf("\n\t\t\tËÅÒÎ\n");
	else if (curUnixTime % LEN_OF_YEAR == WINTER_TIME)
		printf("\n\t\t\tÇÈÌÀ\n");

	/*if (curUnixTime % LEN_OF_YEAR >= SUMMER_TIME && curUnixTime % LEN_OF_YEAR < WINTER_TIME)
		abstractSystems[KEY_ABSTRACT_SYS::Summer_System]->OnTimerTick(curUnixTime);
	else if (curUnixTime % LEN_OF_YEAR >= SUMMER_TIME && curUnixTime % LEN_OF_YEAR < WINTER_TIME)
		abstractSystems[KEY_ABSTRACT_SYS::Winter_System]->OnTimerTick(curUnixTime);*/

	for (auto sys : abstractSystems)
		sys.second->OnTimerTick(curUnixTime);
}

void Hub::discharge_schedules()
{
	for (auto sys : abstractSystems)
		sys.second->discharge_iterators();
}

void Hub::print_schedules(KEY_SUBSYSTEM subSys, KEY_ABSTRACT_SYS abstrSys)
{
	abstractSystems[abstrSys]->print_schedule(subSys);
}
