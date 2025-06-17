#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Question.h"
#include "ShortAnswerQuestion.h"
#include "TrueOrFalseQuestion.h"
#include "SingleChoiceQuestion.h"
#include "MatchingPairsQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "Helpers.h"

static size_t constexpr INITIAL_QUESTIONS_COUNT = 5;

enum class WorkMode
{
	Normal,
	Test
};
class Quiz
{
	static unsigned counter;
private:
	unsigned id;
	MyString title;
	unsigned questionsCount;
	MyVector<Question*> questions;
	MyString createrNames, createrUsername;

	WorkMode mode;
	unsigned playsCount;
	unsigned likesCount;
	int collectedPoints;
	bool shuffleOn; 
	bool liked;

	void free();
	void copyFrom(const Quiz& other);
public:
	Quiz() = default;
	Quiz(const MyString& title, const MyString& createrUsername);
	Quiz(const Quiz& other);
	Quiz& operator=(const Quiz& other);
	~Quiz();

	unsigned getId() const;
	const MyString& getTitle() const;
	unsigned getQuestionsCount() const;
	WorkMode getWorkMode() const;
	unsigned getPlaysCount() const;
	unsigned getLikesCount() const;
	const MyString& getCreaterUsername() const;
	int getCollectedPoints() const;

	void setWorkMode(const WorkMode mode);
	void setNames(const MyString& name, const MyString& family);

	void addQuestion(Question* question);

	void like();
	void unlike();
	bool isLiked() const;

	void shuffle();
	void play();

	void saveToFile(std::ofstream& ofs) const;
	static void saveCurrentQuizIdToBinaryFile(std::ofstream& ofs);
	void readFromBinaryFile(std::ifstream& ifs);
	static void readCurrentQuizIdToBinaryFile(std::ifstream& ifs);
	void saveToBinaryFile(std::ofstream& ofs) const; 

	//void sendToApproval() const;

	void displayQuiz() const;
	void displayPendingQuiz() const;
};

