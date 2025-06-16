#include "ApproveQuizCommand.h"

ApproveQuizCommand::ApproveQuizCommand(unsigned id) : Command(), id(id) {}

void ApproveQuizCommand::execute()
{
	s.approveQuiz(id);
}


