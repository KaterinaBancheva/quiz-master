#pragma once
#include "LoginCommand.h"
#include "QuitCommand.h"
#include "LogoutCommand.h"
#include "HelpCommand.h"
#include "SignUpCommand.h"
#include "ViewProfileCommand.h"
#include "ViewCommand.h"
#include "ViewChallengesCommand.h"
#include "ViewFinishedChallengesCommand.h"
#include "MessagesCommand.h"
#include "CreateQuizCommand.h"
#include "QuizzesCommand.h"
#include "LikeQuizCommand.h"
#include "UnlikeQuizCommand.h"
#include "AddToFavsCommand.h"
#include "RemoveFromFavsCommand.h"
#include "StartQuizNormalCommand.h"
#include "StartQuizTestCommand.h"
#include "SaveQuizCommand.h"
#include "ReportQuizCommand.h"
#include "PendingCommand.h"
#include "ApproveQuizCommand.h"
#include "RejectQuizCommand.h"
#include "ViewReportsCommand.h"
#include "RemoveQuizCommand.h"
#include "BanCommand.h"

class CommandFactory
{
public:
	static Command* generateCommand(const MyString& fullLine);
};

