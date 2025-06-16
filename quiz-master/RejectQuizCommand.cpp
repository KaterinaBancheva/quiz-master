#include "RejectQuizCommand.h"

RejectQuizCommand::RejectQuizCommand(unsigned id, const MyString& reason) : Command(), id(id), reason(reason) {}

void RejectQuizCommand::execute()
{
	s.rejectQuiz(id, reason);
}
