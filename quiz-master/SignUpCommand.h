#pragma once
#include "Command.h"
#include "MyString.h"

class SignUpCommand : public Command
{
private:
	MyString name, familyName, username, password, password2;
public:
	SignUpCommand(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, const MyString& password2);

	void execute() override;
	~SignUpCommand() override = default;
};

