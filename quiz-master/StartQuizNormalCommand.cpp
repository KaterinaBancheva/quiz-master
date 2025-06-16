#include "StartQuizNormalCommand.h"

StartQuizNormalCommand::StartQuizNormalCommand(unsigned id, bool shuffle) : Command(), id(id), shuffle(shuffle) {}

void StartQuizNormalCommand::execute()
{
	s.startQuiz_normal(id, shuffle);
}


