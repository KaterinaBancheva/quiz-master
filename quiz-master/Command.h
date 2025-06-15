#pragma once
#include "System.h"

class Command
{
protected:
	System& s;
public:
	Command() : s(System::getInstance()) {};
	virtual void execute() = 0;
	virtual ~Command() = default;
};

