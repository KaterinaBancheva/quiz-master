#pragma once
#include "Command.h"
class PendingCommand :
    public Command
{
public:
    PendingCommand() = default;

    void execute() override;
    ~PendingCommand() override = default;
};

