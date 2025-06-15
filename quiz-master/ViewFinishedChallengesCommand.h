#pragma once
#include "Command.h"
class ViewFinishedChallengesCommand :
    public Command
{
public:
    ViewFinishedChallengesCommand() = default;

    void execute() override;
    ~ViewFinishedChallengesCommand() override = default;
};

