#include "UserScript.h"
#include <algorithm>
using namespace std;



UserScript::UserScript()
{
}


UserScript::UserScript(UserScript *source) {
	for (auto child : source->children)
		children.push_back(child->clone());
}

UserScript::~UserScript()
{
}

void UserScript::execute()
{
	for (auto child : children)
		child->execute();
}


void UserScript::add(ICommands *component)
{
	children.push_back(component);
}


void UserScript::remove(ICommands* component)
{
	auto iter = find(children.begin(), children.end(), component);
	if (iter != children.end())
		children.erase(iter);
}

int UserScript::get_time_unix()
{
	sort_command();
	return children[0]->get_time_unix();
}

bool compare_command(ICommands *com1, ICommands *com2)
{
	return !com1 || !com2 ? 0 : com1->get_time_unix() < com2->get_time_unix();
}

void UserScript::sort_command()
{
	sort(children.begin(), children.end(), compare_command);
}

//string UserScript::to_string()
//{
//	string s = "";
//	for (auto ch : children)
//		s += ch->to_string() + "\n";
//	return s;
//}

bool UserScript::is_composit()
{
	return true;
}



ICommands * UserScript::clone()
{
	return new UserScript(this);
}




vector<ICommands*> UserScript::get_array_commands()
{
	vector<ICommands*> resArray;
	for (auto item : children)
		if (item->is_composit()) {		//Это композит?
			vector<ICommands*> commsInScript = ((UserScript*)item)->get_array_commands();
			for (auto comm : commsInScript)
				resArray.push_back(comm);
		}
		else
			resArray.push_back(item);
	
	return resArray;
}

vector<ICommands*> UserScript::get_children()
{
	return children;
}

void UserScript::accept(IVisitor * visitor)
{
	visitor->visit(this);
}
