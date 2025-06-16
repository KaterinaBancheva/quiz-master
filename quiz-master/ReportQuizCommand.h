#pragma once
#include "Command.h"
class ReportQuizCommand :
    public Command
{
private:
    unsigned id;
    MyString filepath;
public:
    ReportQuizCommand(unsigned id, const MyString& filpath);

    void execute() override;
    ~ReportQuizCommand() override = default;
};

