#pragma once
#include "IVisitor.h"
#include <map>
using namespace std;
//#include "TypeOfSensor.h"
//#include "Trigger.h"


enum TypeOfSensor;
enum Predicate;


class VisitorToPrintCons :
	public IVisitor
{
private:
	int countTabs;
	map<TypeOfSensor, string> sensor2string;
	map<Predicate, string> predicate2string;

public:
	VisitorToPrintCons();
	~VisitorToPrintCons();

	// Унаследовано через IVisitor
	virtual void visit(Command * com) override;
	virtual void visit(UserScript * script) override;
	virtual void visit(Trigger * trigg) override;
};

