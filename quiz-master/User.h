#pragma once
#include "MyString.h"

class User
{
protected:
	MyString name, familyName, username, password;
public:
	void createQuiz();
	void editQuiz();
};

