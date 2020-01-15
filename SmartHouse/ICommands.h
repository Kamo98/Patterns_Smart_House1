#pragma once
#include <string>
#include "IElementToVisit.h"
using namespace std;

//��������� ��� ������������ ������ � ���������
class ICommands : IElementToVisit
{
public:

	virtual void execute() = 0;			//���������� ������� (������)
	virtual int get_time_unix() = 0;	//�������� ����� ���������� ������� ��� ������ ����� ���������� ��������
	//virtual string to_string() = 0;

	virtual bool is_composit() = 0;
	virtual ICommands* clone() = 0;

	// ������������ ����� IElementToVisit
	virtual void accept(IVisitor * visitor) = 0;
};

