#include "SingleChoiceQuestion.h"
#include <iostream>

SingleChoiceQuestion::SingleChoiceQuestion() : Question(" ", 0) { type = QuestionType::SC; }

SingleChoiceQuestion::SingleChoiceQuestion(const MyString& description, int points, const MyString& a1, const MyString& a2, const MyString& a3,
	const MyString& a4, char right) :Question(description, points) , answer1(a1), answer2(a2), answer3(a3), answer4(a4)
{
    //answer1 = a1;
    //answer2 = a2;
    //answer3 = a3;
    //answer4 = a4;
    rightAnswer = right;
	type = QuestionType::SC;
}

Question* SingleChoiceQuestion::clone() const
{
    return new SingleChoiceQuestion(*this);
}

void SingleChoiceQuestion::answerTest()
{
	char answer;
	std::cin >> answer;
	if (answer == rightAnswer)
	{
		std::cout << "Correct!\n";
	}
	else
	{
		std::cout << "The correct answer is " << rightAnswer << '\n';
	}
}

bool SingleChoiceQuestion::answerNormal()
{
	char answer;
	std::cin >> answer;
	if (answer == rightAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SingleChoiceQuestion::printTest() const
{
	std::cout << description << "\n";
	std::cout << "A. " << answer1 << '\n';
	std::cout << "B. " << answer2 << '\n';
	std::cout << "C. " << answer3 << '\n';
	std::cout << "D. " << answer4 << '\n';
	std::cout << "Enter your choice here: ";
}

void SingleChoiceQuestion::printNormal() const
{
	std::cout << description << " ( " << points << " points )\n";
	std::cout << "A. " << answer1 << '\n';
	std::cout << "B. " << answer2 << '\n';
	std::cout << "C. " << answer3 << '\n';
	std::cout << "D. " << answer4 << '\n';
	std::cout << "Enter your choice here: ";
}

void SingleChoiceQuestion::saveToFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		throw std::runtime_error("File cannot be opened!");
	}

	ofs << "SingleChoiceQuestion ";
    ofs << description << "\n";
	ofs << "A. " << answer1 << '\n';
	ofs << "B. " << answer2 << '\n';
	ofs << "C. " << answer3 << '\n';
	ofs << "D. " << answer4 << '\n';
	ofs << "Enter your choice here: ";
}

void SingleChoiceQuestion::saveToBinaryFile(std::ofstream& ofs) const
{
	description.write(ofs);
	ofs.write((const char*)&points, sizeof(points));
	answer1.write(ofs);
	answer2.write(ofs);
	answer3.write(ofs);
	answer4.write(ofs);
	ofs.write((const char*)&rightAnswer, sizeof(char));
}

void SingleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs)
{
	description.read(ifs);
	ifs.read((char*)&points, sizeof(points));
	answer1.read(ifs);
	answer2.read(ifs);
	answer3.read(ifs);
	answer4.read(ifs);
	ifs.read(&rightAnswer, sizeof(char));
}
