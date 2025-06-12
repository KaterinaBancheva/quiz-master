#include "MultipleChoiceQuestion.h"
#include <iostream>
#include <sstream>

char MultipleChoiceQuestion::getLetter(const char* str)
{
	if (!str) return '\0';
	
    char result = 0;
	size_t i = 0;
	
	while (str[i] == ' ') i++;

	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		result = str[i];
		return result;
	}

	return '\0';
}

MyString MultipleChoiceQuestion::normalize(const MyString& str)
{
	MyString toReturn = str;

	int i = 0;
	while (toReturn[i])
	{
		if (toReturn[i] >= 'a' && toReturn[i] <= 'z')
		{
			//toReturn[i] = std::toupper(toReturn[i]);
			toReturn[i] = 'A' + toReturn[i] - 'a';
		}
		i++;
	}

	return toReturn;
}


bool MultipleChoiceQuestion::contains(char ch) const
{
	for (size_t i = 0; i < rightAnswers.getSize(); i++)
	{
		if (rightAnswers[i] == ch)
			return true;
	}
	return false;
}

MultipleChoiceQuestion::MultipleChoiceQuestion() : Question("", 0) {}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MyString& description, int points, const MyVector<MyString>& options,
	const MyVector<char>& rightAnswers) : Question(description, points)
{
	if (options.getSize() < MIN_ANSWERS_COUNT || rightAnswers.getSize() < MIN_RIGHT_ANSWERS_COUNT)
		throw std::invalid_argument("Invalid options!");

	this->options = options;
	this->rightAnswers = rightAnswers;
	pointsToGet = points;
}

int MultipleChoiceQuestion::getQuestionPoints() const
{
	return pointsToGet;
}

Question* MultipleChoiceQuestion::clone() const
{
	return new MultipleChoiceQuestion(*this);
}

void MultipleChoiceQuestion::answerTest()
{
	MyString answer;
	std::cin >> answer;
	answer = normalize(answer);
	std::stringstream ss(answer.c_str());
	std::string token;
	MyVector<char> userAnswers;

	while (std::getline(ss, token, ','))
	{
		char option = getLetter(token.c_str());
		userAnswers.push_back(option);
	}

	int correct = 0;
	for (size_t i = 0; i < userAnswers.getSize(); i++)
	{
		if (contains(userAnswers[i]))
		{
			correct++;
		}
	}

	if (correct == (int)rightAnswers.getSize())
	{
		std::cout << "Correct!\n";
	}
	else
	{
		std::cout << "The correct answers are ";
		for (size_t i = 0; i < rightAnswers.getSize(); i++)
		{
			std::cout << rightAnswers[i];
			if (i != (int)rightAnswers.getSize() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << '\n';
	}
}

bool MultipleChoiceQuestion::answerNormal()
{
	MyString answer;
	std::cin >> answer;
	answer = normalize(answer);
	std::stringstream ss(answer.c_str());
	std::string token;
	MyVector<char> userAnswers;

	while (std::getline(ss, token, ','))
	{
		char option = getLetter(token.c_str());
		userAnswers.push_back(option);
	}

	int correct = 0;
	for (size_t i = 0; i < userAnswers.getSize(); i++)
	{
		if (contains(userAnswers[i]))
		{
			correct++;
		}
	}

	if (correct == (int)rightAnswers.getSize())
	{
		return true;
	}
	else if (correct * 2 >= (int)rightAnswers.getSize())
	{
		pointsToGet /= 2;
		return true;
	}
	else
	{
		return false;
	}
}

void MultipleChoiceQuestion::printTest() const
{
	std::cout << description << "\n";
	for (size_t i = 0; i < options.getSize(); i++)
	{
		char letter = 'A' + i;
		std::cout << letter << ". " << options[i].c_str() << '\n';
	}
	std::cout << "Enter your answers here: ";
}

void MultipleChoiceQuestion::printNormal() const
{
	std::cout << description << " ( " << points << " points )\n";
	for (size_t i = 0; i < options.getSize(); i++)
	{
		char letter = 'A' + i;
		std::cout << letter << ". " << options[i].c_str() << '\n';
	}
	std::cout << "Enter your answers here: ";
}

void MultipleChoiceQuestion::saveToFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		throw std::runtime_error("File cannot be opened!");
	}

	ofs << "MultipleChoiceQuestion ";
	ofs << description << "\n";
	for (size_t i = 0; i < options.getSize(); i++)
	{
		char letter = 'A' + i;
		ofs << letter << ". " << options[i] << '\n';
	}
	ofs << "Enter your answers here: ";
}

void MultipleChoiceQuestion::saveToBinaryFile(std::ofstream& ofs) const
{
	description.write(ofs);
	ofs.write((const char*)&points, sizeof(points));
	size_t size = options.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < options.getSize(); i++)
	{
		options[i].write(ofs);
	}
	size = rightAnswers.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < rightAnswers.getSize(); i++)
	{
		ofs.write((const char*)&rightAnswers[i], sizeof(char));
	}
}

void MultipleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs)
{
	options.clear();
	rightAnswers.clear();

	description.read(ifs);
	ifs.read((char*)&points, sizeof(points));
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		MyString temp;
		temp.read(ifs);
		options.push_back(std::move(temp));
	}
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		char temp;
		ifs.read(&temp, sizeof(char));
		rightAnswers.push_back(temp);
	}
}

