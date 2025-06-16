#include "StartQuizTestCommand.h"

StartQuizTestCommand::StartQuizTestCommand(unsigned id, bool shuffle) : Command(), id(id), shuffle(shuffle) {}

void StartQuizTestCommand::execute()
{
	s.startQuiz_test(id, shuffle);
}
