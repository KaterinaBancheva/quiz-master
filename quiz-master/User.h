#pragma once
#include "MyString.h"

class User
{
protected:
	MyString name, familyName, username, password;
public:
	virtual void viewProfile() const;

	void createQuiz();
	void editQuiz();
};

