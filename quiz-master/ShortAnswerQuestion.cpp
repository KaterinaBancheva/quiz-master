#include "ShortAnswerQuestion.h"
#include <iostream>
#include <string>
#include <algorithm>

void ShortAnswerQuestion::normalizeAnswer(MyString& str)
{
	size_t len = str.getSize();
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

std::string ShortAnswerQuestion::trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	size_t end = str.find_last_not_of(" \t\n\r\f\v");
	return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

ShortAnswerQuestion::ShortAnswerQuestion() : Question(" ", 0) { type = QuestionType::ShA; }

ShortAnswerQuestion::ShortAnswerQuestion(const MyString& description, int points, const MyString& correctAnswer)
	:Question(description, points)
{
	this->correctAnswer = correctAnswer;
	type = QuestionType::ShA;
}

Question* ShortAnswerQuestion::clone() const
{
	return new ShortAnswerQuestion(*this);
}

void ShortAnswerQuestion::answerTest()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//MyString answer;
	std::string temp;
	std::getline(std::cin, temp);
	//answer = temp.c_str();
	temp = trim(temp);

	std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	MyString answer = temp.c_str();

	normalizeAnswer(answer);

	if (answer == correctAnswer)
	{
		std::cout << "Correct!\n";
	}
	else
	{
		std::cout << "The correct answer is " << correctAnswer << '\n';
	}
}

bool ShortAnswerQuestion::answerNormal()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	MyString answer;
	std::string temp;
	std::getline(std::cin, temp);
	answer = temp.c_str();
	normalizeAnswer(answer);

	if (answer == correctAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ShortAnswerQuestion::printTest() const
{
	std::cout << description << "\nEnter your answer here: ";
}

void ShortAnswerQuestion::printNormal() const
{
	std::cout << description << " ( " << points << " points )\nEnter your answer here: ";
}

void ShortAnswerQuestion::saveToFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		throw std::runtime_error("File cannot be opened!");
	}

	ofs << "ShortAnswerQuestion " << description << "\nEnter yout answer here: \n";
	
}

void ShortAnswerQuestion::saveToBinaryFile(std::ofstream& ofs) const
{
	description.write(ofs);
	ofs.write((const char*)&points, sizeof(points));
	correctAnswer.write(ofs);
}

void ShortAnswerQuestion::readFromBinaryFile(std::ifstream& ifs)
{
	description.read(ifs);
	ifs.read((char*)&points, sizeof(points));
	correctAnswer.read(ifs);
}
