#pragma once
#include "Command.h"
class MessagesCommand :
    public Command
{
public:
    MessagesCommand() = default;
    
    void execute() override;
    ~MessagesCommand() override = default;
};

