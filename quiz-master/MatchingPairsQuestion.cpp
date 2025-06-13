#include "MatchingPairsQuestion.h"
#include <iostream>
#include <sstream>

bool MatchingPairsQuestion::contains(const Pair& p) const
{
	for (size_t i = 0; i < answers.getSize(); i++)
	{
		if (answers[i] == p)
			return true;
	}
	return false;
}

MatchingPairsQuestion::MatchingPairsQuestion()
    :Question(" ", 0) {}

MatchingPairsQuestion::MatchingPairsQuestion(const MyString& description, int points, MyVector<MyString>& leftColumn,
	MyVector<MyString>& rightColumn, MyVector<Pair>& answers): Question(description, points)
{
    this->leftColumn = leftColumn;
    this->rightColumn = rightColumn;
	this->answers = answers;
	this->pointsToGet = points;
}

int MatchingPairsQuestion::getQuestionPoints() const
{
    return pointsToGet;
}

Question* MatchingPairsQuestion::clone() const
{
    return new MatchingPairsQuestion(*this);
}

void MatchingPairsQuestion::answerTest()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string tempLine;
	std::getline(std::cin, tempLine); 
	MyString input(tempLine.c_str()); 

	const char* cstr = input.c_str();
	size_t len = input.getSize();
	size_t i = 0;
	MyVector<Pair> userAnswers;

	while (i < len)
	{
		while (i < len && cstr[i] != '(') i++;

		if (i >= len) break;

		i++;
		MyString pairContent;

		while (i < len && cstr[i] != ')')
		{
			if (cstr[i] != ' ')
				pairContent += cstr[i];

			i++;
		}


		if (i >= len || cstr[i] != ')')
		{
			std::cout << "Invalid format: missing ')' in input.\n";
			return;
		}

		i++; 

		Pair p = Helpers::getPair(pairContent.c_str());
		userAnswers.push_back(p);
	}

	int correct = 0;
	for (size_t i = 0; i < userAnswers.getSize(); i++)
	{
		if (contains(userAnswers[i]))
		{
			correct++;
		}
	}

	if (correct == (int)answers.getSize())
	{
		std::cout << "Correct!\n";
	}
	else
	{
		std::cout << "You got " << correct << " out of " << answers.getSize() << " correct.\n";
		std::cout << "The correct pairs are ";
		for (size_t i = 0; i < answers.getSize(); i++)
		{
			std::cout << answers[i];
			if (i != (int)answers.getSize() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << '\n';
	}
}

bool MatchingPairsQuestion::answerNormal()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string tempLine;
	std::getline(std::cin, tempLine);
	//std::cin >> tempLine;
	MyString input(tempLine.c_str());

	const char* cstr = input.c_str();
	size_t len = input.getSize();
	size_t i = 0;
	MyVector<Pair> userAnswers;

	while (i < len)
	{
		while (i < len && cstr[i] != '(') i++;

		if (i >= len) break;

		i++;
		MyString pairContent;

		while (i < len && cstr[i] != ')')
		{
			if (cstr[i] != ' ')
				pairContent += cstr[i];

			i++;
		}


		if (i >= len || cstr[i] != ')')
		{
			std::cout << "Invalid format: missing ')' in input.\n";
			return false;
		}

		i++;

		Pair p = Helpers::getPair(pairContent.c_str());
		userAnswers.push_back(p);
	}

	int correct = 0;
	for (size_t i = 0; i < userAnswers.getSize(); i++)
	{
		if (contains(userAnswers[i]))
		{
			correct++;
		}
	}

	if (correct == (int)answers.getSize())
	{
		return true;
	}
	else if (correct * 2 >= (int)answers.getSize())
	{
		pointsToGet /= 2;
		return true;
	}
	else
	{
		return false;
	}
}

int getAlignment(const MyVector<MyString>& options) 
{
	int max = options[0].getSize();

	for (size_t i = 1; i < options.getSize(); i++)
	{
		if (options[i].getSize() > max)
		{
			max = options[i].getSize();
		}
	}

	return max;
}

MyString getTabs(const MyString& str, int alignment)
{
	int len = str.getSize();
	int diff = alignment - len;
	MyString toReturn;
	for (size_t i = 0; i < diff; i++)
	{
		toReturn += ' ';
	}

	return toReturn;
}

void MatchingPairsQuestion::printTest() const
{
	std::cout << description << "\n";
	bool areLeftMore = (leftColumn.getSize() > rightColumn.getSize());

	size_t maxElementsCount;
	if (areLeftMore)
	{
		maxElementsCount = leftColumn.getSize();
	}
	else
	{
		maxElementsCount = rightColumn.getSize();
	}

	int alignment = getAlignment(leftColumn);
	int toCompare = getAlignment(rightColumn);
	if (toCompare > alignment) alignment = toCompare;

	for (size_t i = 0; i < maxElementsCount; i++)
	{
		char letter = 'A' + i;
		MyString tabs = getTabs(leftColumn[i].c_str(), alignment);

		char letter_ = letter - 'A' + 'a';
		if (areLeftMore && rightColumn.getSize() - 1 < i)
		{
			std::cout << letter << ". " << leftColumn[i].c_str() << '\n';
		}
		else if ((!areLeftMore)&& leftColumn.getSize()-1 < i)
		{
			std::cout << " . " << leftColumn[i].c_str() << tabs << letter_ << ". " << rightColumn[i] << '\n';
		}
		else
		{
			std::cout << letter << ". " << leftColumn[i].c_str() << tabs << letter_ << ". " << rightColumn[i] << '\n';
		}
	}
	std::cout << "Enter your pairs here: ";
}

void MatchingPairsQuestion::printNormal() const
{
	std::cout << description << " ( " << points << " points )\n";
	bool areLeftMore = (leftColumn.getSize() > rightColumn.getSize());

	size_t maxElementsCount;
	if (areLeftMore)
	{
		maxElementsCount = leftColumn.getSize();
	}
	else
	{
		maxElementsCount = rightColumn.getSize();
	}

	int alignment = getAlignment(leftColumn);
	int toCompare = getAlignment(rightColumn);
	if (toCompare > alignment) alignment = toCompare;

	for (size_t i = 0; i < maxElementsCount; i++)
	{
		char letter = 'A' + i;
		MyString tabs = getTabs(leftColumn[i].c_str(), alignment);
		char letter_ = letter - 'A' + 'a';

		if (areLeftMore && rightColumn.getSize() - 1 < i)
		{
			std::cout << letter << ". " << leftColumn[i].c_str() << '\n';
		}
		else if ((!areLeftMore) && leftColumn.getSize() - 1 < i)
		{
			std::cout << " . " << leftColumn[i].c_str() << tabs << letter_ << ". " << rightColumn[i] << '\n';
		}
		else
		{
			std::cout << letter << ". " << leftColumn[i].c_str() << tabs << letter_ << ". " << rightColumn[i] << '\n';
		}
	}
	std::cout << "Enter your pairs here: ";
}

void MatchingPairsQuestion::saveToFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		throw std::runtime_error("File cannot be opened!");
	}

	ofs << "MatchingPairsQuestion ";
	ofs << description << "\n";
	bool areLeftMore = (leftColumn.getSize() > rightColumn.getSize());

	size_t maxElementsCount;
	if (areLeftMore)
	{
		maxElementsCount = leftColumn.getSize();
	}
	else
	{
		maxElementsCount = rightColumn.getSize();
	}

	int alignment = getAlignment(leftColumn);
	int toCompare = getAlignment(rightColumn);
	if (toCompare > alignment) alignment = toCompare;

	for (size_t i = 0; i < maxElementsCount; i++)
	{
		char letter = 'A' + i;
		MyString tabs = getTabs(leftColumn[i].c_str(), alignment);
		char letter_ = letter - 'A' + 'a';
		ofs << letter << ". " << leftColumn[i].c_str() << tabs << letter_ << ". " << rightColumn[i] << '\n';
	}
	ofs << "Enter your answers here: ";
}

void MatchingPairsQuestion::saveToBinaryFile(std::ofstream& ofs) const
{
	description.write(ofs);
	ofs.write((const char*)&points, sizeof(points));
	size_t size = leftColumn.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < leftColumn.getSize(); i++)
	{
		leftColumn[i].write(ofs);
	}
	size = rightColumn.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < rightColumn.getSize(); i++)
	{
		rightColumn[i].write(ofs);
	}
	size = answers.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < answers.getSize(); i++)
	{
		answers[i].saveToBinaryFile(ofs);
	}
}

void MatchingPairsQuestion::readFromBinaryFile(std::ifstream& ifs)
{
	answers.clear();
	leftColumn.clear();
	rightColumn.clear();

	description.read(ifs);
	ifs.read((char*)&points, sizeof(points));
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		MyString temp;
		temp.read(ifs);
		leftColumn.push_back(std::move(temp));
	}
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		MyString temp;
		temp.read(ifs);
		rightColumn.push_back(std::move(temp));
	}
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		Pair temp;
		temp.readFromBinaryFile(ifs);
		answers.push_back(std::move(temp));
	}
}


