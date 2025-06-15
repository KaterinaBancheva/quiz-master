#include "ViewCommand.h"

ViewCommand::ViewCommand(const MyString& username) : Command(), username(username) {}

void ViewCommand::execute()
{
	s.view(username);
}

