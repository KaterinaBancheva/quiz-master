#pragma once
#include "User.h"
#include "Administrator.h"
#include "Player.h"
#include "Quiz.h"
#include "Message.h"
#include "SingleChoiceQuestion.h"
#include "MatchingPairsQuestion.h"
#include "TrueOrFalseQuestion.h"
#include "ShortAnswerQuestion.h"
#include "MultipleChoiceQuestion.h"

class System
{
private:
	MyVector<Message> allMessages;
	MyVector<Quiz> allQuizzes;
	MyVector<User*> allUsers;
	User* loggedUser;

	int findQuizById(unsigned id) const;
	int findUserByNickname(const MyString& nickname) const;
public:
	void login(const MyString& username, const MyString& password);
	void logout();
	void help();

	/*void saveToBinaryFile();
	void readFromBinaryFile(); */
	
	//player function
	void signUp(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, const MyString& password2);
	void viewProfile() const;
	void view(const MyString& nickname) const;
	void viewChallenges() const;
	void viewFinishedChallenges() const;
	void messages() const;
	void createQuiz();
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

	//admin functions
	void pending() const;
	void approveQuiz(unsigned quizId); // const
	void rejectQuiz(unsigned quizId, const MyString& reasoh); // const
	void viewReports() const;
	void removeQuiz(unsigned quizId, MyString reason);//const
	void ban(MyString username) const; //not shure
};

