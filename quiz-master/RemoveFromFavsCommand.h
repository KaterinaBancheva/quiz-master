#pragma once
#include "Command.h"
class RemoveFromFavsCommand :
    public Command
{
private:
    unsigned id;
public:
    RemoveFromFavsCommand(unsigned id);

    void execute() override;
    ~RemoveFromFavsCommand() override = default;
};

