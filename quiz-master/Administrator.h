#pragma once
#include "User.h"

class Administrator : public User
{
public:
	Administrator(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, UserType& type);

	void pending() const;
	void approveQuiz(unsigned quizId); // const
	void rejectQuiz(unsigned quizId, const MyString& reasoh); // const
	void viewReports() const;
	void removeQuiz(unsigned quizId, MyString reason);//const
	void ban(MyString username) const; //not shure

	UserType getUserType() const override;
	void saveToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;
};