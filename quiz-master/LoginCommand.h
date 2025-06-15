#pragma once
#include "Command.h"

class LoginCommand : public Command
{
private:
	MyString username, password;
public:
	LoginCommand(const MyString& username, const MyString& password);

	void execute() override;
	~LoginCommand() override = default;
};

