#include "Administrator.h"

Administrator::Administrator() : User(" ", " ", " ", " ")
{
	type = UserType::Admin;
}

Administrator::Administrator(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password)
	:User(name, familyName, username, password)
{
	type = UserType::Admin;
}

UserType Administrator::getUserType() const
{
	return UserType::Admin;
}

void Administrator::saveToBinaryFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&type, sizeof(type));
	name.write(ofs);
	familyName.write(ofs);
	username.write(ofs);
	password.write(ofs);
}

void Administrator::readFromBinaryFile(std::ifstream& ifs)
{
	ifs.read((char*)&type, sizeof(type));
	name.read(ifs);
	familyName.read(ifs);
	username.read(ifs);
	password.read(ifs);
}
