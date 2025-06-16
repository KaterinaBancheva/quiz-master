#pragma once
#include "Command.h"
class CreateQuizCommand :
    public Command
{
public:
    CreateQuizCommand() = default;

    void execute() override;
    ~CreateQuizCommand() override = default;
};

