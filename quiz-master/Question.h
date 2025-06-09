#pragma once
#include "MyString.h"

class Question
{
protected:
	MyString description;
	int points;
public:
	Question(const MyString& description, int points);

	virtual Question* clone() const = 0;
	virtual void answerTest() = 0;
	virtual bool answerNormal() = 0;
	virtual void printTest() const = 0;
	virtual void printNormal() const = 0;
	virtual ~Question() = default;

	virtual void saveToFile(std::ofstream& ofs) const = 0;
	virtual void saveToBunaryFile(std::ofstream& ofs) const = 0;
	virtual void readFromBinaryFile(std::ifstream& ifs) = 0;

	int getQuestionPoints() const;
	const MyString& getDescription() const;
};

