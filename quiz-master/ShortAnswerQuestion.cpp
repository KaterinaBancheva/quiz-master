#include "ShortAnswerQuestion.h"
#include <iostream>

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

ShortAnswerQuestion::ShortAnswerQuestion(const MyString& description, int points, const MyString& correctAnswer)
	:Question(description, points)
{
	this->correctAnswer = correctAnswer;
}

Question* ShortAnswerQuestion::clone() const
{
	return new ShortAnswerQuestion(*this);
}

void ShortAnswerQuestion::answerTest()
{
	MyString answer;
	std::cin >> answer;
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
	MyString answer;
	std::cin >> answer;
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
