#include "BanCommand.h"

BanCommand::BanCommand(const MyString& username) : Command(), username(username) {}

void BanCommand::execute()
{
	s.ban(username);
}

