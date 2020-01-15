#pragma once
#include "ICommands.h"
#include <vector>

using namespace std;


class UserScript : public ICommands
{
private:
	vector<ICommands*> children;
public:
	UserScript(UserScript *source);
	UserScript();
	~UserScript();

	// ������������ ����� ICommands
	virtual void execute() override;		//���������� ������ ���� ��������
	void add(ICommands *component);			//���������� ����������
	void remove(ICommands* component);		//�������� ����������



	// ������������ ����� ICommands
	virtual int get_time_unix() override;

	vector<ICommands*> get_array_commands();		//�������� ������ ������� � ���� �������
	vector<ICommands*> get_children();


													// ������������ ����� ICommands
	virtual ICommands * clone() override;


	// ������������ ����� ICommands
	virtual void accept(IVisitor * visitor) override;

private:
	void sort_command();
	//bool compare_command(ICommands &com1, ICommands &com2);


	// ������������ ����� ICommands
	/*virtual string to_string() override;*/


	// ������������ ����� ICommands
	virtual bool is_composit() override;





};

