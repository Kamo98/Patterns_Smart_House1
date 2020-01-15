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

	// Унаследовано через ICommands
	virtual void execute() override;		//Выполнение команд всех потомков
	void add(ICommands *component);			//Добавление компонента
	void remove(ICommands* component);		//Удаление компонента



	// Унаследовано через ICommands
	virtual int get_time_unix() override;

	vector<ICommands*> get_array_commands();		//Получить список коммнад в виде массива
	vector<ICommands*> get_children();


													// Унаследовано через ICommands
	virtual ICommands * clone() override;


	// Унаследовано через ICommands
	virtual void accept(IVisitor * visitor) override;

private:
	void sort_command();
	//bool compare_command(ICommands &com1, ICommands &com2);


	// Унаследовано через ICommands
	/*virtual string to_string() override;*/


	// Унаследовано через ICommands
	virtual bool is_composit() override;





};

