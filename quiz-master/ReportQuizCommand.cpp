#include "ReportQuizCommand.h"

ReportQuizCommand::ReportQuizCommand(unsigned id, const MyString& filpath) :Command(), id(id), filepath(filepath) {}

void ReportQuizCommand::execute()
{
	s.reportQuiz(id, filepath);
}
