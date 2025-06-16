#pragma once
#include "Command.h"
class RejectQuizCommand :
    public Command
{
private:
    unsigned id;
    MyString reason;
public:
    RejectQuizCommand(unsigned id, const MyString& reason);

    void execute() override;
    ~RejectQuizCommand() override = default;
};

