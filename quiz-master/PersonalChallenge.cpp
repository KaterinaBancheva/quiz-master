#include "PersonalChallenge.h"

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

	message = 
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
