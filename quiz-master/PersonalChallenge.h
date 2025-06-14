#pragma once
#include "Challenge.h"
#include "User.h"
#include <ctime>
#include <cstring>
#pragma warning (disable:4996)

class PersonalChallenge
{
private:
	unsigned challengeId;
	MyString username;
	time_t time;
	MyString date;
	MyString message;
public:
	PersonalChallenge();
	PersonalChallenge(const MyString& username, unsigned challengeId);

	const MyString& getMessage() const;
	const MyString& getUsername() const;
	unsigned getChallengeId() const;
	const MyString& getTime() const;

	void print(const Challenge* c) const;

	void saveToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);

};

