#pragma once
#include "Command.h"
class UnlikeQuizCommand :
    public Command
{
private:
    unsigned id;
public:
    UnlikeQuizCommand(unsigned id);

    void execute() override;
    ~UnlikeQuizCommand() override = default;
};

