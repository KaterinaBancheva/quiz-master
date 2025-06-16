#include "SaveQuizCommand.h"

SaveQuizCommand::SaveQuizCommand(unsigned id, const MyString& filpath) : Command(), id(id), filepath(filepath) {}

void SaveQuizCommand::execute()
{
	s.saveQuiz(id, filepath);
}


