#pragma once
#include <string>
#include "IElementToVisit.h"
using namespace std;

//Интерфейс для компоновщика команд и сценариев
class ICommands : IElementToVisit
{
public:

	virtual void execute() = 0;			//Выполнение команды (команд)
	virtual int get_time_unix() = 0;	//Получить время выполнения команды или раннее время выполнения сценария
	//virtual string to_string() = 0;

	virtual bool is_composit() = 0;
	virtual ICommands* clone() = 0;

	// Унаследовано через IElementToVisit
	virtual void accept(IVisitor * visitor) = 0;
};

