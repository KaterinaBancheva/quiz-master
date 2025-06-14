#pragma once
#include "MyVector.hpp"
#include "User.h"
#include "Quiz.h"
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
public:
	Player(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, UserType& type);

	void signUp(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, const MyString& password2);
	void viewProfile() const;
	void viewChallenges() const;
	void viewFinishedChallenges() const;
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
};