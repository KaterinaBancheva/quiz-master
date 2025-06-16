#pragma once
#include "Command.h"
class LikeQuizCommand :
    public Command
{
private:
    unsigned id;
public:
    LikeQuizCommand(unsigned id);

    void execute() override;
    ~LikeQuizCommand() override = default;
};

