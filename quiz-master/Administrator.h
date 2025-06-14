#pragma once
#include "User.h"

class Administrator : public User
{
public:
	Administrator();
	Administrator(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password);

	UserType getUserType() const override;
	void saveToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;
	~Administrator() override = default;
};