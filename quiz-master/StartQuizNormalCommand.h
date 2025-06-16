#pragma once
#include "Command.h"
class StartQuizNormalCommand :
    public Command
{
private:
    unsigned id;
    bool shuffle;
public:
    StartQuizNormalCommand(unsigned id, bool shuffle);

    void execute() override;
    ~StartQuizNormalCommand() override = default;
};

