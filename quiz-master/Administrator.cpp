#include "Administrator.h"

Administrator::Administrator(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, UserType& type)
	:User(name, familyName, username, password)
{
	this->type = type;
}

UserType Administrator::getUserType() const
{
	return UserType::Admin;
}
