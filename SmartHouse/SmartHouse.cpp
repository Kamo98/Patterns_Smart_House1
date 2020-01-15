#include <locale.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
#include <thread>
#include <chrono>
#include "Appliance.h"
#include "ProxyAppliance.h"
#include "RealAppliance.h"
#include "Sensor.h"
#include "Thermometer.h"
#include "HumidityMeter.h"
#include "Trigger.h"
#include "Command.h"
#include "WarmFloor.h"
#include "Humidifier.h"
#include "UserScript.h"
#include "SmartLampAdapter.h"
#include "ExecutionSchedule.h"
#include "IIterator.h"
#include "IteratorExecSchedule.h"
#include "SensorLogger.h"
#include "VoiceNotification.h"
#include "SmsNotification.h"
#include "Timer.h"
#include "IElementToVisit.h"
#include "VisitorToPrintCons.h"
#include "UserInterface.h"


//������������ ������ ��� ��������
//void test_proxy() {
//	ProxyAppliance *prox1 = new ProxyAppliance(), *prox2 = new ProxyAppliance();
//	WarmFloor *app1 = new WarmFloor("Ҹ���� ��� 1"), *app2 = new WarmFloor("Ҹ���� ��� 2"), *app3 = new WarmFloor("Ҹ���� ��� 3");
//	prox1->init_appliance(app1);
//	string command = "test command";
//
//	const int N = 3;
//	IAppliance* apps[N] = { prox1, prox2, app3 };
//
//	for (int i = 0; i < N; i++) {
//		printf("������ %d: ", i + 1);
//		apps[i]->execute_command(command, map<string, int>());
//		printf("\n");
//	}
//
//	printf("\n\n");
//
//	//������������� ������������ ��������
//	app1->turn_on();	//���
//	app2->block();		//������.
//	prox1->init_appliance(app1);
//	prox2->init_appliance(app2);
//
//	for (int i = 0; i < N; i++) {
//		printf("������ %d: ", i + 1);
//		apps[i]->execute_command(command, map<string, int>());
//		printf("\n");
//	}
//}


//������������ ������������� (��������->���������)
void test_delegate() {
	Thermometer *term1 = new Thermometer("��������� 1", 15);
	HumidityMeter *humid1 = new HumidityMeter("���������� ��������� 1", 30);

	//����� ��������� ����������� ��������
	printf("����������� �� ������� = %d C\n", term1->get_value());
	printf("��������� ������� �� ������� = %d %\n", humid1->get_value());


	Trigger *trig1 = new Trigger();
	trig1->add_condition(term1, 20, Predicate::MORE_EQUAL);		//������� �� ����������� >= 20
	trig1->add_condition(humid1, 35, Predicate::EQUAL);			//��������� == 35


	if (trig1->is_trigger_on())
		printf("������ �� ����������� >= 20 � ��������� == 35 �������\n");
	else
		printf("������ �� ����������� >= 20 � ��������� == 35 �� �������\n");


	term1->set_value(40);
	humid1->set_value(35);


	printf("\n\n����������� �� ������� = %d C\n", term1->get_value());
	printf("��������� ������� �� ������� = %d %\n", humid1->get_value());
	
	if (trig1->is_trigger_on())
		printf("������ �� ����������� >= 20 � ��������� == 35 �������\n");
	else
		printf("������ �� ����������� >= 20 � ��������� == 35 �� �������\n");


	
	trig1->add_condition(term1, 30, Predicate::LESS_EQUAL);		//�������� ������� �� ����������� <= 30

	
	printf("\n\n����������� �� ������� = %d C\n", term1->get_value());
	printf("��������� ������� �� ������� = %d %\n", humid1->get_value());

	if (trig1->is_trigger_on())
		printf("������ �� ����������� >= 20 � <= 30 � ��������� == 35 �������\n");
	else
		printf("������ �� ����������� >= 20 � <= 30 � ��������� == 35 �� �������\n");

}


//������������ ������������
/*
 * ���� ���������� �� �������� 
 */
void test_l4() {

	//������� ��������� ����������
	WarmFloor *warmFloor1 = new WarmFloor("Ҹ���� ��� 1"), *warmFloor2 = new WarmFloor("Ҹ���� ��� 2");
	Humidifier *hum1 = new Humidifier("����������� 1");

	SmartLamp *smartLamp = new SmartLamp();		//������, ��������� �������� �� �� �����
	SmartLampAdapter *adpLamp = new SmartLampAdapter("������� ����� ����� 1", smartLamp);


	CommandFactory *comFact = new CommandFactory();


	/*
	* ������� ������� � ������� ��� ���������	
	*/
	Command *com1 = new Command(comFact, warmFloor1, "�������� ��������", 10);
	Command *com2 = new Command(comFact, warmFloor1, "�������� ��������", 20);
	Command *com3 = new Command(comFact, warmFloor2, "��������� ��������", 40);
	Command *com4 = new Command(comFact, hum1, "Test command 2", 30);
	Command *com5 = new Command(comFact, hum1, "Test command 3", 50);

	Command *com6 = new Command(comFact, warmFloor1, "���������� ������������� ���������", 100);
	com6->set_param("intensity", 8);
	



	Command *comLamp1 = new Command(comFact, adpLamp, SmartLampAdapter::COM_TURN_ON, 200);

	Command *comLamp2 = new Command(comFact, adpLamp, "���������� ���� ���������", 300);
	comLamp2->set_param("colorR", 128);
	comLamp2->set_param("colorG", 128);
	comLamp2->set_param("colorB", 255);

	Command *comLamp3 = new Command(comFact, adpLamp, "���������� ������������� ���������", 400);
	comLamp3->set_param("intensity", 12);




	//������� ��������
	UserScript *script1 = new UserScript();
	script1->add(com2);
	script1->add(com1);

	UserScript *script2 = new UserScript();
	script2->add(com3);
	script2->add(com4);

	UserScript *scriptLamp1 = new UserScript();
	scriptLamp1->add(comLamp1);
	scriptLamp1->add(comLamp2);

	UserScript *scriptLamp2 = new UserScript();
	scriptLamp2->add(comLamp3);
	scriptLamp2->add(scriptLamp1);
	/*********************/



	/*
	* ������� ��������
	*/
	Thermometer *term1 = new Thermometer("��������� 1", 15);
	HumidityMeter *humid1 = new HumidityMeter("���������� ��������� 1", 30);

	Trigger *trig20_35 = new Trigger();
	trig20_35->add_condition(term1, 20, Predicate::MORE_EQUAL);		//������� �� ����������� >= 20
	trig20_35->add_condition(humid1, 35, Predicate::EQUAL);			//��������� == 35

	Trigger *trig30_25 = new Trigger();
	trig30_25->add_condition(term1, 30, Predicate::MORE_EQUAL);		//������� �� ����������� >= 30
	trig30_25->add_condition(humid1, 25, Predicate::LESS);			//��������� < 25

	/*************************/




	//������� ���������� ���������� ������ � ���������
	ExecutionSchedule *schedule = new ExecutionSchedule();

	schedule->insert(script1, trig20_35);
	schedule->insert(com5, trig20_35);
	schedule->insert(script2, trig20_35);
	schedule->insert(com6, trig30_25);
	schedule->insert(scriptLamp2, trig30_25);
	schedule->insert(comLamp1, trig30_25);



	//����� ���� ������ � ��������� 
	IIterator<pair<ICommands*, Trigger*>> *iter1 = schedule->create_iterator();

	VisitorToPrintCons *visitor = new VisitorToPrintCons();

	printf("\n\t\t�� ���������� �������� � ������ � ����������\n\n");
	while (iter1->has_current()) {
		printf("\n\n==========================\n\n");
		//printf("%s", iter1->get_cur().first->to_string().c_str());
		IElementToVisit* elem = (IElementToVisit*) iter1->get_cur().first;
		elem->accept(visitor);
		iter1->get_cur().second->accept(visitor);
		iter1->to_next();
	}


	//iter1 = schedule->create_iterator();
	//printf("\n\n\n\t\t����� ���������� �������� � ������ � ����������\n\n");
	//while (iter1->has_current()) {
	//	printf("\n\n==========================\n\n");
	//	//printf("%s", iter1->get_cur().first->to_string().c_str());
	//	IElementToVisit* elem = (IElementToVisit*)iter1->get_cur().first;
	//	elem->accept(visitor);
	//	iter1->get_cur().second->accept(visitor);
	//	iter1->to_next();
	//}
}


void test_decorator() {
	Thermometer *term1 = new Thermometer("��������� 1", 15);
	HumidityMeter *humid1 = new HumidityMeter("���������� ��������� 1", 30);

	SensorLogger *logger = new SensorLogger("log.txt");

	SmsNotification *sms = new SmsNotification(logger);			//���������� �����

	term1->add_listener(sms);
	humid1->add_listener(sms);


	//��������� ����������� ��������
	term1->set_value(18);
	humid1->set_value(32);

	printf("\n\n=====================\n");



	//���������� ���������
	VoiceNotification *voice = new VoiceNotification(sms);
	

	term1 = new Thermometer("��������� 1", 15);
	humid1 = new HumidityMeter("���������� ��������� 1", 30);

	term1->add_listener(voice);		//��������� ������ � ��������� � ����������
	humid1->add_listener(voice);	//��������� ������ � ��������� � ���������� ���������


	//��������� ����������� ��������
	term1->set_value(12);
	humid1->set_value(29);

}



int main()
{
	setlocale(LC_CTYPE, "Rus");
	/*map<StateDevice, string> state2str;
	state2str[StateDevice::LOCKED] = "LOCKED";
	state2str[StateDevice::OVERLOAD] = "OVERLOAD";
	state2str[StateDevice::SWITCHED_OFF] = "SWITCHED_OFF";
	state2str[StateDevice::SWITCHED_ON] = "SWITCHED_ON";*/


	//test_proxy();
	//test_delegate();

	//test_l4();

	//test_decorator();

	/*for (int i = 0; i < 5; i++) {
		printf("main id = %d\n", this_thread::get_id());
		this_thread::sleep_for(chrono::milliseconds(1000));
	}*/

	//test_l4();	


	UserInterface *UI = new UserInterface();

	//��������� - ��������� ���������� +
	//����������� +
	//��������� (��� ��������� ����������)

	//�������(���������, ����)
	//���������� (��� ������ � ������� ������������ � ���������) +
	//��������������� (���� ����� ������ � ������� ����������)

	//������� ������������ (�������� ��������� ������, �� � ������� ������ ��������� ������� ������)
	//���������
	//���������
    return 0;
}