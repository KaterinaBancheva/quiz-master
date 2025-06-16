#pragma once
#include "Command.h"
class ApproveQuizCommand :
    public Command
{
private:
    unsigned id;
public:
    ApproveQuizCommand(unsigned id);

    void execute() override;
    ~ApproveQuizCommand() override = default;
};

