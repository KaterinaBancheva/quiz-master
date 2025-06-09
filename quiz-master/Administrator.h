#pragma once
#include "User.h"

class Administrator : public User
{
public:
	void pending() const;
	void approveQuiz(unsigned quizId); // const
	void rejectQuiz(unsigned quizId, const MyString& reasoh); // const
	void viewReports() const;
	void removeQuiz(unsigned quizId, MyString reason);//const
	void ban(MyString username) const; //not shure
};