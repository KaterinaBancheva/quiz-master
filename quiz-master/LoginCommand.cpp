#include "LoginCommand.h"

LoginCommand::LoginCommand(const MyString& username, const MyString& password)
{
	this->username = username;
	this->password = password;
}

void LoginCommand::execute()
{
	s.login(username, password);
}
