#pragma once
#include "Command.h"
class HelpCommand :
    public Command
{
public:
    HelpCommand() = default;

    void execute() override;
    ~HelpCommand() override = default;
};

