#pragma once
#include "MyString.h"
#include <iostream>
#include <ctime>
#pragma warning (disable:4996)

class Report
{
private:
	MyString reporterUsername;
	MyString creatorUsername;
	MyString reason;
	int quizId;
	time_t timestamp;
public:
	Report();
	Report(const MyString& reporterUsername, const MyString& creatorUsername, int quizId, const MyString& reason);

	void print() const;
	void saveToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);
};

