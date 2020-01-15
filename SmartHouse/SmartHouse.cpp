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


//Тестирование прокси для приборов
//void test_proxy() {
//	ProxyAppliance *prox1 = new ProxyAppliance(), *prox2 = new ProxyAppliance();
//	WarmFloor *app1 = new WarmFloor("Тёплый пол 1"), *app2 = new WarmFloor("Тёплый пол 2"), *app3 = new WarmFloor("Тёплый пол 3");
//	prox1->init_appliance(app1);
//	string command = "test command";
//
//	const int N = 3;
//	IAppliance* apps[N] = { prox1, prox2, app3 };
//
//	for (int i = 0; i < N; i++) {
//		printf("Прибор %d: ", i + 1);
//		apps[i]->execute_command(command, map<string, int>());
//		printf("\n");
//	}
//
//	printf("\n\n");
//
//	//Инициализация проксируемых приборов
//	app1->turn_on();	//Вкл
//	app2->block();		//Заблок.
//	prox1->init_appliance(app1);
//	prox2->init_appliance(app2);
//
//	for (int i = 0; i < N; i++) {
//		printf("Прибор %d: ", i + 1);
//		apps[i]->execute_command(command, map<string, int>());
//		printf("\n");
//	}
//}


//Тестирование делегирования (источник->слушатель)
void test_delegate() {
	Thermometer *term1 = new Thermometer("Термометр 1", 15);
	HumidityMeter *humid1 = new HumidityMeter("Измеритель влажности 1", 30);

	//Вывод начальных показателей датчиков
	printf("Температура на датчике = %d C\n", term1->get_value());
	printf("Влажность воздуха на датчике = %d %\n", humid1->get_value());


	Trigger *trig1 = new Trigger();
	trig1->add_condition(term1, 20, Predicate::MORE_EQUAL);		//триггер на температуру >= 20
	trig1->add_condition(humid1, 35, Predicate::EQUAL);			//влажность == 35


	if (trig1->is_trigger_on())
		printf("Тригер на температуру >= 20 и влажность == 35 включён\n");
	else
		printf("Тригер на температуру >= 20 и влажность == 35 НЕ включён\n");


	term1->set_value(40);
	humid1->set_value(35);


	printf("\n\nТемпература на датчике = %d C\n", term1->get_value());
	printf("Влажность воздуха на датчике = %d %\n", humid1->get_value());
	
	if (trig1->is_trigger_on())
		printf("Тригер на температуру >= 20 и влажность == 35 включён\n");
	else
		printf("Тригер на температуру >= 20 и влажность == 35 НЕ включён\n");


	
	trig1->add_condition(term1, 30, Predicate::LESS_EQUAL);		//добавить условие на температуру <= 30

	
	printf("\n\nТемпература на датчике = %d C\n", term1->get_value());
	printf("Влажность воздуха на датчике = %d %\n", humid1->get_value());

	if (trig1->is_trigger_on())
		printf("Тригер на температуру >= 20 и <= 30 и влажность == 35 включён\n");
	else
		printf("Тригер на температуру >= 20 и <= 30 и влажность == 35 НЕ включён\n");

}


//Тестирование компоновщика
/*
 * Надо избавиться от хардкода 
 */
void test_l4() {

	//Создать отдельные устройства
	WarmFloor *warmFloor1 = new WarmFloor("Тёплый пол 1"), *warmFloor2 = new WarmFloor("Тёплый пол 2");
	Humidifier *hum1 = new Humidifier("Увлажнитель 1");

	SmartLamp *smartLamp = new SmartLamp();		//прибор, интерфейс которого мы не знаем
	SmartLampAdapter *adpLamp = new SmartLampAdapter("Адаптер умной лампы 1", smartLamp);


	CommandFactory *comFact = new CommandFactory();


	/*
	* Создать команды и скрипты для устройств	
	*/
	Command *com1 = new Command(comFact, warmFloor1, "Включить подогрев", 10);
	Command *com2 = new Command(comFact, warmFloor1, "Включить подогрев", 20);
	Command *com3 = new Command(comFact, warmFloor2, "Отключить подогрев", 40);
	Command *com4 = new Command(comFact, hum1, "Test command 2", 30);
	Command *com5 = new Command(comFact, hum1, "Test command 3", 50);

	Command *com6 = new Command(comFact, warmFloor1, "Установить интенсивность подогрева", 100);
	com6->set_param("intensity", 8);
	



	Command *comLamp1 = new Command(comFact, adpLamp, SmartLampAdapter::COM_TURN_ON, 200);

	Command *comLamp2 = new Command(comFact, adpLamp, "Установить цвет освещения", 300);
	comLamp2->set_param("colorR", 128);
	comLamp2->set_param("colorG", 128);
	comLamp2->set_param("colorB", 255);

	Command *comLamp3 = new Command(comFact, adpLamp, "Установить интенсивность освещения", 400);
	comLamp3->set_param("intensity", 12);




	//Создать сценарии
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
	* Создать триггеры
	*/
	Thermometer *term1 = new Thermometer("Термометр 1", 15);
	HumidityMeter *humid1 = new HumidityMeter("Измеритель влажности 1", 30);

	Trigger *trig20_35 = new Trigger();
	trig20_35->add_condition(term1, 20, Predicate::MORE_EQUAL);		//триггер на температуру >= 20
	trig20_35->add_condition(humid1, 35, Predicate::EQUAL);			//влажность == 35

	Trigger *trig30_25 = new Trigger();
	trig30_25->add_condition(term1, 30, Predicate::MORE_EQUAL);		//триггер на температуру >= 30
	trig30_25->add_condition(humid1, 25, Predicate::LESS);			//влажность < 25

	/*************************/




	//Создать расписание выполнения команд и сценариев
	ExecutionSchedule *schedule = new ExecutionSchedule();

	schedule->insert(script1, trig20_35);
	schedule->insert(com5, trig20_35);
	schedule->insert(script2, trig20_35);
	schedule->insert(com6, trig30_25);
	schedule->insert(scriptLamp2, trig30_25);
	schedule->insert(comLamp1, trig30_25);



	//Вывод всех команд и сценариев 
	IIterator<pair<ICommands*, Trigger*>> *iter1 = schedule->create_iterator();

	VisitorToPrintCons *visitor = new VisitorToPrintCons();

	printf("\n\t\tДо сортировки скриптов и команд в расписании\n\n");
	while (iter1->has_current()) {
		printf("\n\n==========================\n\n");
		//printf("%s", iter1->get_cur().first->to_string().c_str());
		IElementToVisit* elem = (IElementToVisit*) iter1->get_cur().first;
		elem->accept(visitor);
		iter1->get_cur().second->accept(visitor);
		iter1->to_next();
	}


	//iter1 = schedule->create_iterator();
	//printf("\n\n\n\t\tПосле сортировки скриптов и команд в расписании\n\n");
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
	Thermometer *term1 = new Thermometer("Термометр 1", 15);
	HumidityMeter *humid1 = new HumidityMeter("Измеритель влажности 1", 30);

	SensorLogger *logger = new SensorLogger("log.txt");

	SmsNotification *sms = new SmsNotification(logger);			//Декорируем логер

	term1->add_listener(sms);
	humid1->add_listener(sms);


	//Изменение показателей датчиков
	term1->set_value(18);
	humid1->set_value(32);

	printf("\n\n=====================\n");



	//Декорируем декоратор
	VoiceNotification *voice = new VoiceNotification(sms);
	

	term1 = new Thermometer("Термометр 1", 15);
	humid1 = new HumidityMeter("Измеритель влажности 1", 30);

	term1->add_listener(voice);		//Добавляем логгер в слушаетли к термометру
	humid1->add_listener(voice);	//Добавляем логгер в слушаетли к измерителю влажности


	//Изменение показателей датчиков
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

	//Состояние - состояние устройства +
	//Наблюдатель +
	//Хранитель (для редактора расписаний)

	//Команда(интерфейс, меню)
	//Посетитель (для вывода в консоль компоновщика и триггеров) +
	//Перенаправление (надо найти классы с высокой связностью)

	//Цепочка обязанностей (возможно обработка ошибок, но в крайнем случае обработка нажатия клавиш)
	//Посредник
	//Стратегия
    return 0;
}