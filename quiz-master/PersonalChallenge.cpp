#include "PersonalChallenge.h"
#include <iostream>

PersonalChallenge::PersonalChallenge() : time (std::time(nullptr))
{
	username = " ";
	message = " ";
	challengeId = 0;
}

PersonalChallenge::PersonalChallenge(const MyString& username, unsigned challengeId) : time(std::time(nullptr))
{
	this->username = username;
	this->challengeId = challengeId;

	message = "New challenge completed! ";
}

const MyString& PersonalChallenge::getMessage() const
{
	return message;
}

const MyString& PersonalChallenge::getUsername() const
{
	return username;
}

unsigned PersonalChallenge::getChallengeId() const
{
	return challengeId;
}

const MyString& PersonalChallenge::getTime() const
{
	return ctime(&time);
}

void PersonalChallenge::print(const Challenge* c) const
{
	const char* timeStr = std::ctime(&time); 
	if (timeStr)
	{
		const char* timeStr = std::ctime(&time);

		char day[3], month[4], year[5];

		std::strncpy(month, timeStr + 4, 3);  month[3] = '\0';
		std::strncpy(day, timeStr + 8, 2);  day[2] = '\0';
		std::strncpy(year, timeStr + 20, 4); year[4] = '\0';

		MyString finalDate = MyString(day) + " " + MyString(month) + " " + MyString(year);
		std::cout << finalDate << " | ";
	}
	else
	{
		std::cout << "            | ";
	}

	std::cout << c->getText() << '\n';
}

void PersonalChallenge::saveToBinaryFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&challengeId, sizeof(challengeId));
	username.write(ofs);
	ofs.write((const char*)&time, sizeof(time));
	message.write(ofs);
}

void PersonalChallenge::readFromBinaryFile(std::ifstream& ifs)
{
	ifs.read((char*)&challengeId, sizeof(challengeId));
	username.read(ifs);
	ifs.read((char*)&time, sizeof(time));
	message.read(ifs);
}
