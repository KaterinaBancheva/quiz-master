#include "Challenge.h"

unsigned counter = 0;

Challenge::Challenge()
{
	id = counter;
	counter++;
	text = " ";
	type = ChallengeType::CreatedQuizes;
}

Challenge::Challenge(const MyString& text, ChallengeType& type)
{
	id = counter;
	counter++;
	this->text = text;
	this->type = type;
}

const MyString& Challenge::getText() const
{
	return text;
}

unsigned Challenge::getId() const
{
	return id;
}

int Challenge::getCount() const
{
	return count;
}

ChallengeType Challenge::getChallengeType() const
{
	return type;
}

int Challenge::getPoints()
{
	switch (type)
	{
	case ChallengeType::SolvingInTestMode: return (count * 10) / 3;
	case ChallengeType::SolvingInNormalMode: return 2 * (count * 10) / 3;
	case ChallengeType::CreatedQuizes: return (count * 10) / 2;
	default: return 0;
	}
}

void Challenge::saveToBinaryFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&id, sizeof(id));
	text.write(ofs);
	ofs.write((const char*)&count, sizeof(count));
	ofs.write((const char*)&type, sizeof(type));
}

void Challenge::readFromBinaryFile(std::ifstream& ifs)
{
	ifs.read(( char*)&id, sizeof(id));
	text.read(ifs);
	ifs.read((char*)&count, sizeof(count));
	ifs.read((char*)&type, sizeof(type));
}
