#pragma once
#include "Command.h"

class ViewReportsCommand : public Command
{
public:
	ViewReportsCommand() = default;

	void execute() override;
	~ViewReportsCommand() override = default;
};

