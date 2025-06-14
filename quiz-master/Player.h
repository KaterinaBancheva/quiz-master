#pragma once
#include "Quiz.h"
#include "MyVector.hpp"
#include "User.h"
#include "PersonalChallenge.h"

class Player : public User
{
private:
	unsigned quizzesInNormalMode, quizzesInTestMode;

	int points;
	MyVector<unsigned> liked;
	MyVector<unsigned> favourites; 
	unsigned level;
	MyVector<unsigned> createdQuizes;
	MyVector<PersonalChallenge> challenges;

	bool contains(unsigned id) const;
	int findQuizById(const MyVector<Quiz>& vector, unsigned id) const;
public:
	Player();
	Player(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password);

	void viewProfile(const MyVector<Quiz>& allQuizzes) const; // level!!!!!
	void viewFinishedChallenges(const MyVector<Challenge> allChallenges) const;
	void createQuiz(unsigned id);

	void addToFavs(unsigned quizId);
	void removeFromFavs(unsigned quizId);
	void likeQuiz(unsigned quizId);
	void unlikeQuiz(unsigned quizId);

	void getPointsNormal(int points);
	void getPointsTest();

	unsigned getQuizzesInNormalMode() const;
	unsigned getQuizzesInTestMode() const;
	unsigned getCreatedQuizzes() const;

	void finishChallenge(unsigned id);

	UserType getUserType() const override;
	void saveToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;
	~Player() override = default;
};