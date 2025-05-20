#pragma once
#include "MyString.h"

class Question
{
protected:
	MyString description;
	int points;
public:
	virtual void clone() const = 0;
	virtual void collectPoints() = 0;

	int getCollectedPoints() const;
	const MyString& getDescription() const;

};

