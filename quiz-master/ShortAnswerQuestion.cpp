#include "ShortAnswerQuestion.h"
#include <iostream>

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
	std::cout << description << "\nEnter your answer here : ";
}

void ShortAnswerQuestion::printNormal() const
{
	std::cout << description << " ( " << points << " points )\nEnter your answer here... : ";
}

void ShortAnswerQuestion::saveToFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		std::runtime_error("File cannot be opened!");
	}

	ofs << "ShortAnswerQuestion " << description << "\nEnter yout answer here... \n";
	
}

void ShortAnswerQuestion::saveToBunaryFile(std::ofstream& ofs) const
{
	description.write(ofs);
	ofs.write((const char*)&points, sizeof(points));
	correctAnswer.write(ofs);

	/*size_t size = description.getSize();
	os.write((const char*)&size, sizeof(size));
	os.write((const char*)&description, sizeof(description));
	os.write((const char*)&points, sizeof(points));
	size = correctAnswer.getSize();
	os.write((const char*)&correctAnswer, sizeof(correctAnswer));*/
}

void ShortAnswerQuestion::readFromBinaryFile(std::ifstream& ifs)
{
	description.read(ifs);
	ifs.read((char*)&points, sizeof(points));
	correctAnswer.read(ifs);

	/*MyString buff;
	size_t size = 0;
	is.read((char*)&size, sizeof(size));
	is.read((char*)&buff, size + 1);
	description =
	is.read((char*)&points, sizeof(points));
	is.read((char*)&correctAnswer, sizeof(correctAnswer));*/
}
