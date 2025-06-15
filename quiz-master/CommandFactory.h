#pragma once
#include "LoginCommand.h"
#include "QuitCommand.h"
#include "LogoutCommand.h"
#include "SignUpCommand.h"
#include "ViewProfileCommand.h"
#include "ViewCommand.h"
#include "ViewChallengesCommand.h"
#include "ViewFinishedChallengesCommand.h"
#include "MessagesCommand.h"
#indlude "CreateQuizCommand.h"

class CommandFactory
{
public:
	static Command* generateCommand(const MyString& fullLine);
};

