#pragma once
#include "MyString.h"

enum class ChallengeType 
{
	SolvingInTestMode,
	SolvingInNormalMode,
	CreatedQuizes
};

class Challenge
{
private:

	static unsigned counterChallenge;

	unsigned id;
	MyString text;
	int count;
	ChallengeType type;

public:
	Challenge();
	Challenge(ChallengeType& type, int count);

	const MyString& getText() const;
	unsigned getId() const;
	int getCount() const;
	ChallengeType getChallengeType() const;

	int getPoints() const;
	void print() const;

	void saveToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);
};

