#pragma once
#include "User.h"

class Player : public User
{
private:
	int points;
	unsigned* favoirites; // quizId
	unsigned level;
	// vector<Challenge> challenges
public:
	void signUp(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, const MyString& password2);
	void viewPrifile() const;
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
	void startQuiz(unsigned quizId /* work mode - separate file */);
	void startQuiz(unsigned quizId, /* work mode - separate file */ bool shuffle);
	void saveQuiz(unsigned quizId, const MyString& filepath);
	void reportQuiz(unsigned quizId, const MyString& reason);
};