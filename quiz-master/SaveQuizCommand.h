#pragma once
#include "Command.h"
class SaveQuizCommand :
    public Command
{
private:
    unsigned id;
    MyString filepath;
public:
    SaveQuizCommand(unsigned id, const MyString& filpath);

    void execute() override;
    ~SaveQuizCommand() override = default;
};

