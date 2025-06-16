#pragma once
#include "Command.h"
class AddToFavsCommand :
    public Command
{
private:
    unsigned id;
public:
    AddToFavsCommand(unsigned id);

    void execute() override;
    ~AddToFavsCommand() override = default;
};

