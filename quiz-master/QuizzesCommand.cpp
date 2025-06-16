#include "QuizzesCommand.h"

QuizzesCommand::QuizzesCommand() : Command()
{
	username = nullptr;
}

QuizzesCommand::QuizzesCommand(const MyString& username)
{
	this->username = username;
}

void QuizzesCommand::execute()
{
	if (username == nullptr)
		s.quizzes();
	else
		s.quizzes(username);
}
