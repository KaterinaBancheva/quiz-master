#pragma once
#include "Command.h"
class ReportQuizCommand :
    public Command
{
private:
    unsigned id;
    MyString reason;
public:
    ReportQuizCommand(unsigned id, const MyString& reason);

    void execute() override;
    ~ReportQuizCommand() override = default;
};

