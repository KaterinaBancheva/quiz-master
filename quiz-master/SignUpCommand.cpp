#include "SignUpCommand.h"

SignUpCommand::SignUpCommand(const MyString& name, const MyString& familyName, const MyString& username,
	const MyString& password, const MyString& password2) : Command(), name(name), familyName(familyName),
	username(username), password(password), password2(password2) {}

void SignUpCommand::execute()
{
	s.signUp(name, familyName, username, password, password2);
}
