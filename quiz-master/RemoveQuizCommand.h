#pragma once
#include "Command.h"
class RemoveQuizCommand :
    public Command
{
private:
    unsigned id;
    MyString reason;
public:
    RemoveQuizCommand(unsigned id, const MyString& reason);

    void execute() override;
    ~RemoveQuizCommand() override = default;
};

