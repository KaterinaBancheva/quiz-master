#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Question.h"

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
	bool shuffleOn; // may be function
	bool liked; // when profile

	//bool favourites; // -> player functions
	MyVector<unsigned> shuffleArray(size_t size) const;
public:
	Quiz() = default;
	Quiz(const MyString& title);

	unsigned getId() const;
	const MyString& getTitle() const;
	unsigned getQuestionsCount() const;
	WorkMode getWorkMode() const;
	unsigned getPlaysCount() const;
	unsigned getLikesCount() const;
	const MyString& getCreaterUsername() const;

	void setWorkMode(const WorkMode mode);

	void addQuestion(Question* question);

	void like();
	void unlike();
	bool isLiked() const;

	void shuffle(); // ?
	void play();

	void saveToFile(std::ofstream& ofs) const;
	void readFromBinaryFile();
	void saveToBinaryFile();

	void sendToApproval() const;

	void displayQuiz() const;

	// void addToFavourites(); -> player functions
};

