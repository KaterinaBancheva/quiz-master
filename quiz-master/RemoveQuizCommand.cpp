#include "RemoveQuizCommand.h"

RemoveQuizCommand::RemoveQuizCommand(unsigned id, const MyString& reason) : Command(), id(id), reason(reason) {}

void RemoveQuizCommand::execute()
{
	s.removeQuiz(id, reason);
}


