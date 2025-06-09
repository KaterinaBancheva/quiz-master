#pragma once
#include "MyVector.hpp"
#include "User.h"

class Player : public User
{
private:
	int points;
	MyVector<unsigned> liked;
	MyVector<unsigned> favoirites; // quizId
	unsigned level;
	MyVector<unsigned> createdQuizes;
	//MyVector<Challenge> challenges
public:
	void viewProfile() const override;

	void signUp(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, const MyString& password2);
	void editProfile();
	void viewChallenges() const;
	void viewFinishedChallenges() const;
	void view(const MyString& nickname) const;
	void messages() const;
	void createQuiz();
	void ediQuiz(unsigned quizId);
	void quizzes() const;
	void quizzes(const MyString& username) const;
	void likeQuiz(unsigned quizId);
	void unlikeQuiz(unsigned quizId);
	void addToFavs(unsigned quizId);
	void removeFromFavs(unsigned quizId);
	void startQuiz_normal(unsigned quizId, bool shuffle);
	void startQuiz_test(unsigned quizId, bool shuffle);
	void saveQuiz(unsigned quizId, const MyString& filepath);
	void reportQuiz(unsigned quizId, const MyString& reason);
};