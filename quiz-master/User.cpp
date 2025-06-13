#include "User.h"

User::User(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password)
{
	this->name = name;
	this->familyName = familyName;
	this->username = username;
	this->password = password;
}

const MyString& User::getName() const
{
	return name;
}

const MyString& User::getFamilyName() const
{
	return familyName;
}

const MyString& User::getUsername() const
{
	return username;
}
