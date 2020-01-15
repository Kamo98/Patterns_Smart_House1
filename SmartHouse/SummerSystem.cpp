#include "SummerSystem.h"



SummerSystem::SummerSystem(CommandFactory *_commandFactory) : AbstractSubSystem(_commandFactory)
{
}


SummerSystem::~SummerSystem()
{
}

void SummerSystem::buildClimateSystem()
{/*
	* ������� ������� � ������� ��� ���������
	*/
	if (subSystems.count(KEY_SUBSYSTEM::Climate_System) == 0) {
		printf("������! ������������� ������� ��� �� ����������������");
		return;
	}

	SubSystem *climate = subSystems[KEY_SUBSYSTEM::Climate_System];

	IAppliance* hum1 = climate->request_appliance("����������� 1");
	Sensor *humMeter = climate->request_sensor("���������� ��������� 1");
	
	Command *com6 = new Command(commandFactory, hum1, "Test command 1", 21);
	Command *com7 = new Command(commandFactory, hum1, "Test command 2", 22);
	Command *com8 = new Command(commandFactory, hum1, "Test command 3", 23);
	Command *com33 = new Command(commandFactory, hum1, "Test TRIGGER", 23);

	//������� ��������
	UserScript *script1 = new UserScript();
	script1->add(com6);
	script1->add(com7);

	UserScript *script2 = new UserScript();
	script2->add(com8);
	script2->add(script1);

	UserScript *script3 = new UserScript();
	script3->add(script2);

	/*********************/


	Trigger *trig3 = new Trigger();
	trig3->add_condition(humMeter, 35, Predicate::EQUAL);		//��������� >= 35

	//������� ���������� ���������� ������ � ���������
	ExecutionSchedule *schedule = new ExecutionSchedule();

	schedule->insert(script3, nullptr);
	schedule->insert(com33, trig3);

	add_schedule(KEY_SUBSYSTEM::Climate_System, schedule);
}

void SummerSystem::buildSecureSystem()
{
}

void SummerSystem::buildLightingSystem()
{
	if (subSystems.count(KEY_SUBSYSTEM::Lighting_System) == 0) {
		printf("������! ������������� ���������� �� ����������������");
		return;
	}
	SubSystem *lightingSystem = subSystems[KEY_SUBSYSTEM::Lighting_System];


	SmartLampAdapter* smartLamp1 = (SmartLampAdapter*)lightingSystem->request_appliance("������� ����� ����� 1");
	SmartLampAdapter* smartLamp2 = (SmartLampAdapter*)lightingSystem->request_appliance("������� ����� ����� 2");

	Command *com1 = new Command(commandFactory, smartLamp1, SmartLampAdapter::COM_TURN_ON, 22);
	Command *com2 = new Command(commandFactory, smartLamp1, SmartLampAdapter::COM_TURN_OFF, 31);
	Command *com3 = new Command(commandFactory, smartLamp1, SmartLampAdapter::COM_SET_INTENSITY, 27);
	com3->set_param(SmartLampAdapter::PARAM_INTENSITY, 20);

	//������� ���������� ���������� ������ � ���������
	ExecutionSchedule *schedule = new ExecutionSchedule();

	schedule->insert(com1, nullptr);
	schedule->insert(com2, nullptr);
	schedule->insert(com3, nullptr);

	add_schedule(KEY_SUBSYSTEM::Lighting_System, schedule);
}
