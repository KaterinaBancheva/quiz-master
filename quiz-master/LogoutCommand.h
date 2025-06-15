#pragma once
#include "Command.h"
class LogoutCommand : public Command
{
public:
	LogoutCommand() = default;

	void execute() override;
	~LogoutCommand() override = default;
};

