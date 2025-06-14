#include "Report.h"

using std::ctime;
using std::strncpy;

Report::Report(): timestamp(std::time(nullptr))
{
	reporterUsername = MyString();
	creatorUsername = MyString();
	reason = MyString();
}

Report::Report(const MyString& reporterUsername, const MyString& creatorUsername, int quizId, const MyString& reason):
	timestamp(std::time(nullptr)), reporterUsername(reporterUsername), creatorUsername(creatorUsername), reason(reason), quizId(quizId) {}

void Report::print() const
{
    const char* timeStr = ctime(&timestamp);
    if (timeStr)
    {
        char timePart[9];
        strncpy(timePart, timeStr + 11, 8); // HH:MM:SS is at position 11–18
        timePart[8] = '\0';

        std::cout << timePart << " | sent by " << reporterUsername << ": " << " | quiz id " <<quizId << "  by " << creatorUsername << 
            " | reason " << reason << std::endl;
    }
    else
    {
        std::cout << "Invalid time, sent by " << reporterUsername << ": " << " | quiz id " << quizId << "  by " << creatorUsername <<
            " | reason " << reason << std::endl;
    }
}

void Report::saveToBinaryFile(std::ofstream& ofs) const
{
    reporterUsername.write(ofs);
    creatorUsername.write(ofs);
    ofs.write((const char*)&quizId, sizeof(quizId));
    reason.write(ofs);
    ofs.write((const char*)&timestamp, sizeof(timestamp));
}

void Report::readFromBinaryFile(std::ifstream& ifs)
{
    reporterUsername.read(ifs);
    creatorUsername.read(ifs);
    ifs.read((char*)&quizId, sizeof(quizId));
    reason.read(ifs);
    ifs.read((char*)&timestamp, sizeof(timestamp));
}
