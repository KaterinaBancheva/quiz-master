#pragma once
#include "Command.h"
class ViewCommand :
    public Command
{
private:
    MyString username;
public:
    ViewCommand(const MyString& username);

    void execute() override;
    ~ViewCommand() override = default;
};

