#include "UnlikeQuizCommand.h"

UnlikeQuizCommand::UnlikeQuizCommand(unsigned id) : Command()
{
	this->id = id;
}

void UnlikeQuizCommand::execute()
{
	s.unlikeQuiz(id);
}
