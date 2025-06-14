#pragma once
#include "Quiz.h"
#include "User.h"
#include "Administrator.h"
#include "Player.h"
#include "Message.h"
#include "Report.h"
#include "SingleChoiceQuestion.h"
#include "MatchingPairsQuestion.h"
#include "TrueOrFalseQuestion.h"
#include "ShortAnswerQuestion.h"
#include "MultipleChoiceQuestion.h"

static const MyString bin_messages = "Messages.bin";
static const MyString bin_quizzes = "Quizzes.bin";
static const MyString bin_pending = "Pending.bin";
static const MyString bin_reports = "Reports.bin";
static const MyString bin_users = "Users.bin";
static const MyString bin_challenges = "Challenges.bin";

class System
{
private:
	MyVector<Message> allMessages;
	MyVector<Quiz> allQuizzes, pendingQuizzes;
	MyVector<Report> reports;
	MyVector<User*> allUsers;
	User* loggedUser;
	MyVector<Challenge> allChallenges;

	int findQuizById(unsigned id) const;
	int findPendingQuizById(unsigned id) const;
	int findUserByNickname(const MyString& nickname) const;
	const Challenge* findChallenge(int count, ChallengeType type);
	bool challengeExists(unsigned id) const;

	System();
	~System();

	void saveMessagesToBinaryFile(std::ofstream& ofs) const;
	void saveQuizzesToBinaryFile(std::ofstream& ofs) const;
	void saveUsersToBinaryFile(std::ofstream& ofs) const;
	void savePendingToBinaryFile(std::ofstream& ofs) const;
	void saveReportsToBinaryFile(std::ofstream& ofs) const;
	void saveChallengesToBinaryFile(std::ofstream& ofs) const;

	void readMessagesFromBinaryFile(std::ifstream& ifs);
	void readReportsFromBinaryFile(std::ifstream& ifs);
	void readChallengesFromBinaryFile(std::ifstream& ifs);
	void readUsersFromBinaryFile(std::ifstream& ifs);
	void readPendingFromBinaryFile(std::ifstream& ifs);
	void readQuizzesFromBinaryFile(std::ifstream& ifs);
public:
	System(const System& other) = delete;
	System(System&& other) noexcept = delete;
	System& operator= (const System& other) = delete;

	static System& getInstance();

	void login(const MyString& username, const MyString& password);
	void logout();
	//void help();
	void quit();

	void saveToBinaryFile() const;
	void readFromBinaryFile(); 

	void setChallenges();
	
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
	void approveQuiz(unsigned quizId); 
	void rejectQuiz(unsigned quizId, const MyString& reason);
	void viewReports() const;
	void removeQuiz(unsigned quizId, MyString& reason);
	void ban(const MyString& username);
};

