#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestion.h"
#include <iostream>
#include <sstream>

MyString MultipleChoiceQuestion::normalize(const MyString& str)
{
	MyString toReturn = str;

	int i = 0;
	while (toReturn[i])
	{
		if (toReturn[i] >= 'a' && toReturn[i] <= 'z')
		{
			toReturn[i] = 'A' + toReturn[i] - 'a';
		}
		i++;
	}

	return toReturn;
}

int MultipleChoiceQuestion::toInt(const char* str)
{
		if (!str) return -1;

		int result = 0;
		size_t i = 0;

		while (str[i] == ' ') i++;

		if (str[i] >= '0' && str[i] <= '9') {
			result = str[i] - 'A';
			return result;
		}
}

bool MultipleChoiceQuestion::contains(int indx) const
{
	for (size_t i = 0; i < rightAnswers.getSize(); i++)
	{
		if (rightAnswers[i] == indx)
			return true;
	}
	return false;
}

const char MultipleChoiceQuestion::getLetter(size_t indx)
{
	return 'A' + indx;
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MyString& description, int points, const MyVector<MyString>& options,
	const MyVector<int>& rightAnswers) : Question(description, points)
{
	this->options = options;
	this->rightAnswers = rightAnswers;
}

Question* MultipleChoiceQuestion::clone() const
{
	return new MultipleChoiceQuestion(*this);
}

void MultipleChoiceQuestion::answerTest()
{
	MyString answer;
	std::cin >> answer;
	normalize(answer);
	std::stringstream ss(answer.c_str());
	std::string token;
	MyVector<int> userAnswers;

	while (std::getline(ss, token, ','))
	{
		int index = toInt(token.c_str()) - 1;
		if (index >= 0 && index < (int)options.getSize())
		{
			userAnswers.push_back(index);
		}
	}

	int correct = 0;
	for (size_t i = 0; i < rightAnswers.getSize(); i++)
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
		std::cout << "The correct answer is ";
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
	/*else if (correct * 2 >= (int)rightAnswers.getSize())
	{

	}*/
	return false;
}

void MultipleChoiceQuestion::printTest() const
{
	std::cout << description << "\n";
	for (size_t i = 0; i < options.getSize(); i++)
	{
		char letter = 'A' + i;
		std::cout << letter << options[i].c_str() << '\n';
	}
	std::cout << "Enter your answers here: ";
}

void MultipleChoiceQuestion::printNormal() const
{
	std::cout << description << " ( " << points << " points )\n";
	for (size_t i = 0; i < options.getSize(); i++)
	{
		char letter = 'A' + i;
		std::cout << letter << options[i].c_str() << '\n';
	}
	std::cout << "Enter your answers here: ";
}

void MultipleChoiceQuestion::saveToFile(std::ofstream& ofs) const
{
}

void MultipleChoiceQuestion::saveToBinaryFile(std::ofstream& ofs) const
{
}

void MultipleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs)
{
}

