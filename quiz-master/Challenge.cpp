#include "Challenge.h"
#include <iostream>

//unsigned counter = 0;

Challenge::Challenge()
{
	id = counter;
	counter++;
	text = " ";
	type = ChallengeType::CreatedQuizes;
}

Challenge::Challenge(ChallengeType& type, int count)
{
	id = counter;
	counter++;
	this->type = type;
	this->count = count;

	text = "";
	text += count;
	switch (type)
	{
	case ChallengeType::SolvingInTestMode: text += " quizzes in test mode solved!";
	case ChallengeType::SolvingInNormalMode: text += " quizzes in normal mode solved!";
	case ChallengeType::CreatedQuizes: text += " quizzes created!";
	default: return;
	}
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

int Challenge::getPoints() const
{
	switch (type)
	{
	case ChallengeType::SolvingInTestMode: return (count * 10) / 3;
	case ChallengeType::SolvingInNormalMode: return 2 * (count * 10) / 3;
	case ChallengeType::CreatedQuizes: return (count * 10) / 2;
	default: return 0;
	}
}

void Challenge::print() const
{
	if (type == ChallengeType::CreatedQuizes)
		std::cout << "Create ";
	else
		std::cout << "Solve";

	std::cout << count << " quizzes ";
	switch (type)
	{
	case ChallengeType::SolvingInTestMode: std::cout << " in test mode!\n";
	case ChallengeType::SolvingInNormalMode: std::cout << " in normal mode!\n";
	case ChallengeType::CreatedQuizes: std::cout << '\n';
	default: return;
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
