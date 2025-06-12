#include "MatchingPairsQuestion.h"
#include <iostream>
#include <sstream>

Pair MatchingPairsQuestion::getPair(const char* str)
{
	if (!str) return Pair("", "");

	MyString input(str);

	//bool parsingLhs = true;

	//for (char c : input)
	//{
	//	if (c == ',')
	//	{
	//		parsingLhs = false;
	//		continue;
	//	}
	//	if (c == ' ' || c == ')')
	//		continue;

	//	if (parsingLhs)
	//		lhsStr += c;
	//	else
	//		rhsStr += c;
	//}

	//MyString lhs(lhsStr.c_str());
	//MyString rhs(rhsStr.c_str());


	MyString lhs, rhs;
	size_t i = 0;

	while(str[i] != ',')
	{
		while (str[i] == ' ') i++;

		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			result[0] = str[i];
		}
	}
	lhs = result;

	while (str[i] != ')')
	{
		while (str[i] == ' ') i++;

		if (str[i] >= 'a' && str[i] <= 'a')
		{
			result[0] = str[i];
		}
	}
	rhs = result;

	return Pair(lhs, rhs);
}

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
    pointsToGet = points;
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
	MyString answer;
	std::cin >> answer;
	std::stringstream ss(answer.c_str());
	std::string token;
	MyVector<Pair> userAnswers;

	while (std::getline(ss, token, '('))
	{
		if (token.empty()) continue;

		if (!token.empty() && token.back() == ')')
			token.pop_back();

		Pair ans = getPair(token.c_str());
		userAnswers.push_back(ans);
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
    return false;
}

void MatchingPairsQuestion::printTest() const
{
}

void MatchingPairsQuestion::printNormal() const
{
}

void MatchingPairsQuestion::saveToFile(std::ofstream& ofs) const
{
}

void MatchingPairsQuestion::saveToBinaryFile(std::ofstream& ofs) const
{
}

void MatchingPairsQuestion::readFromBinaryFile(std::ifstream& ifs)
{
}


