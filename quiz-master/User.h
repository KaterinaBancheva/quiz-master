#pragma once
#include "MyString.h"
#include "UserType.h"
class User
{
protected:
	MyString name, familyName, username, password;
	UserType type;
public:
	User(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password);

	const MyString& getName() const;
	const MyString& getFamilyName() const;
	const MyString& getUsername() const;

	bool checkPassword(const MyString& password) const;

	virtual void saveToBinaryFile(std::ofstream& ofs) const = 0;
	virtual void readFromBinaryFile(std::ifstream& ifs) = 0;
	virtual UserType getUserType() const = 0;
	virtual ~User() = default;
};

