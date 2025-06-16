#pragma once
#include "Command.h"
class QuizzesCommand :
    public Command
{
private:
    MyString username;
public:
    QuizzesCommand();
    QuizzesCommand(const MyString& username);

    void execute() override;
    ~QuizzesCommand() override = default;
};

