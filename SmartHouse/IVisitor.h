#pragma once
//#include "Command.h"
//#include "UserScript.h"
//#include "Trigger.h"

class Command;
class UserScript;
class Trigger;

class IVisitor
{
public:
	virtual void visit(Command *com) = 0;
	virtual void visit(UserScript *script) = 0;
	virtual void visit(Trigger *trigg) = 0;
};

