#pragma once
#include "Command.h"

class ViewChallengesCommand :
    public Command
{
public:
    ViewChallengesCommand() = default;

    void execute() override;
    ~ViewChallengesCommand() override = default;
};

