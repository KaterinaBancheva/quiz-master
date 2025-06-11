#include "TrueOrFalseQuestion.h"
#include <iostream>

TrueOrFalseQuestion::TrueOrFalseQuestion(const MyString& description, int points, bool correctAnswer)
	:Question(description, points)
{
	this->correctAnswer = correctAnswer;
}

Question* TrueOrFalseQuestion::clone() const
{
	return new TrueOrFalseQuestion(*this);
}

void TrueOrFalseQuestion::answerTest()
{
	MyString input;
	std::cin >> input;

	bool answer = (input == "true" || input == "1");

	if (answer == correctAnswer)
	{
		std::cout << "Correct!\n";
	}
	else
	{
		if(correctAnswer == true)
		{
			std::cout << "The correct answer is true\n";
		}
		else
		{
			std::cout << "The correct answer is false\n";
		}
	}
}

bool TrueOrFalseQuestion::answerNormal()
{
	MyString input;
	std::cin >> input;

	bool answer = (input == "true" || input == "1");

	if (answer == correctAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TrueOrFalseQuestion::printTest() const
{
	std::cout << description << "\n";
	std::cout << "Enter your answer here (true/false): ";
}

void TrueOrFalseQuestion::printNormal() const
{
	std::cout << description << " ( " << points << " points )\n";
	std::cout << "Enter your answer here (true/false): ";
}

void TrueOrFalseQuestion::saveToFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		throw std::runtime_error("File cannot be opened!");
	}

	ofs << "TrueOrFalseQuestion ";
	ofs << description << "\n";
	ofs << "Enter your answer here (true/false): ";
}

void TrueOrFalseQuestion::saveToBinaryFile(std::ofstream& ofs) const
{
	description.write(ofs);
	ofs.write((const char*)&points, sizeof(points));
	ofs.write((const char*)&correctAnswer, sizeof(bool));
}

void TrueOrFalseQuestion::readFromBinaryFile(std::ifstream& ifs)
{
	description.read(ifs);
	ifs.read((char*)&points, sizeof(points));
	ifs.read((char*)&correctAnswer, sizeof(bool));
}
