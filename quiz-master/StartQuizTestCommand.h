#pragma once
#include "Command.h"
class StartQuizTestCommand :
    public Command
{
private:
    unsigned id;
    bool shuffle;
public:
    StartQuizTestCommand(unsigned id, bool shuffle);

    void execute() override;
    ~StartQuizTestCommand() override = default;
};

