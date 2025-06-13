#pragma once
#include "MyString.h"

enum class ChallengeType 
{
	SolvingInTestMode,
	SolvingInNormalMode,
	CreatedQuizes
};

static unsigned counter;

class Challenge
{
private:
	unsigned id;
	MyString text;
	int count;
	ChallengeType type;

public:
	Challenge();
	Challenge(const MyString& text, ChallengeType& type);

	const MyString& getText() const;
	unsigned getId() const;
	int getCount() const;
	ChallengeType getChallengeType() const;

	int getPoints();

	void saveToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);
};

