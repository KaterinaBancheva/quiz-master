#pragma once
#include "Command.h"
class BanCommand :
    public Command
{
private:
    MyString username;
public:
    BanCommand(const MyString& username);

    void execute() override;
    ~BanCommand() override = default;
};


