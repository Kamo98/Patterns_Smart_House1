#include "UserInterface.h"
#include <conio.h>



UserInterface::UserInterface()
{
	hub = Hub::getInstance();
	hub->init();

	commPrintSchedule[{Climate_System, Summer_System}] 
		= new CommPrintSchedule(Climate_System, Summer_System, hub);
	commPrintSchedule[{Climate_System, Winter_System}]
		= new CommPrintSchedule(Climate_System, Winter_System, hub);
	commPrintSchedule[{Lighting_System, Summer_System}]
		= new CommPrintSchedule(Lighting_System, Summer_System, hub);
	commPrintSchedule[{Lighting_System, Winter_System}]
		= new CommPrintSchedule(Lighting_System, Winter_System, hub);

	main_menu();
}


UserInterface::~UserInterface()
{
}

void UserInterface::main_menu()
{
	while (true) {
		printf("1. ���������\n");
		printf("2. ����������� ���������� ������������� ���������� ��� ������� �������\n");
		printf("3. ����������� ���������� ������������� ���������� ��� ������� �������\n");
		printf("4. ����������� ���������� ������������� ���������� ��� ������� �������\n");
		printf("5. ����������� ���������� ������������� ���������� ��� ������� �������\n");
		printf("6. �����\n");
		printf("\n������� �����: ");
		int c;
		scanf("%d", &c);

		Timer *timer;
		thread *th;
		switch (c) {
		case 1:
			hub->discharge_schedules();

			printf("������� ����� �������, ����� ��������� �������� ������ ����\n");
			printf("��� ���������� ���������� ����� ������� ����� �������\n\n");
			fflush(stdin);
			c = getch();
			timer = new Timer(hub);
			th = new thread(&Timer::run, ref(*timer));

			while (true) {
				c = getch();
				if (c == 27) {
					timer->stop();
					break;
				}
			}

			th->join();
			
			break;
		case 2:
			commPrintSchedule[{Climate_System, Winter_System}]->execute();
			break;
		case 3:
			commPrintSchedule[{Climate_System, Summer_System}]->execute();
			break;
		case 4:
			commPrintSchedule[{Lighting_System, Winter_System}]->execute();
			break;
		case 5:
			commPrintSchedule[{Lighting_System, Summer_System}]->execute();
			break;
		case 6:
			return;
			break;

		}
		printf("\n\n\n\n");
	}
}
