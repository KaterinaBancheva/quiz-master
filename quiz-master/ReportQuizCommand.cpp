#include "ReportQuizCommand.h"

ReportQuizCommand::ReportQuizCommand(unsigned id, const MyString& reason) :Command(), id(id), reason(reason) {}

void ReportQuizCommand::execute()
{
	s.reportQuiz(id, reason);
}
