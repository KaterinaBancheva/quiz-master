#pragma once
#include "Quiz.h"

class System
{
public:
	void login(const MyString& username, const MyString& password);
	void logout();
	void help();
};

