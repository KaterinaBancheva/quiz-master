#include "LikeQuizCommand.h"

LikeQuizCommand::LikeQuizCommand(unsigned id) : Command()
{
	this->id = id;
}

void LikeQuizCommand::execute()
{
	s.likeQuiz(id);
}
