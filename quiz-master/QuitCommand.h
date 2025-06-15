#pragma once
#include "Command.h"

class QuitCommand : public Command
{
public:
	QuitCommand() = default;

	void execute() override;
	~QuitCommand() override = default;
};

