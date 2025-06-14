#pragma once
#include "MyString.h"
enum class QuestionType
{
	ShA,
	SC,
	MC,
	MP,
	TF
};

class Question
{
protected:
	MyString description;
	int points;
	QuestionType type;
public:
	Question(const MyString& description, int points);

	virtual Question* clone() const = 0;
	virtual void answerTest() = 0;
	virtual bool answerNormal() = 0;
	virtual void printTest() const = 0;
	virtual void printNormal() const = 0;
	virtual ~Question() = default;

	virtual void saveToFile(std::ofstream& ofs) const = 0;
	virtual void saveToBinaryFile(std::ofstream& ofs) const = 0;
	virtual void readFromBinaryFile(std::ifstream& ifs) = 0;

	virtual int getQuestionPoints() const;
	const MyString& getDescription() const;
	QuestionType getType() const;
};

