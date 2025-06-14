#include "System.h"
#include <sstream>
#include <iostream>

System::System()
{
	readFromBinaryFile();
}

void System::saveToBinaryFile() const
{
	std::ofstream ofs_mess(bin_messages.c_str(), std::ios::binary);
	saveMessagesToBinaryFile(ofs_mess);
	ofs_mess.close();

	std::ofstream ofs_rep(bin_reports.c_str(), std::ios::binary);
	saveReportsToBinaryFile(ofs_rep);
	ofs_rep.close();

	std::ofstream ofs_chall(bin_challenges.c_str(), std::ios::binary);
	saveChallengesToBinaryFile(ofs_chall);
	ofs_chall.close();

	std::ofstream ofs_users(bin_users.c_str(), std::ios::binary);
	saveUsersToBinaryFile(ofs_users);
	ofs_users.close();

	std::ofstream ofs_pend(bin_pending.c_str(), std::ios::binary);
	savePendingToBinaryFile(ofs_pend);
	ofs_pend.close();

	std::ofstream ofs_quiz(bin_quizzes.c_str(), std::ios::binary);
	saveQuizzesToBinaryFile(ofs_quiz);
	ofs_quiz.close();
}

void System::readFromBinaryFile()
{
	std::ifstream ifs_mess(bin_messages.c_str(), std::ios::binary);
	readMessagesFromBinaryFile(ifs_mess);
	ifs_mess.close();

	std::ifstream ifs_rep(bin_reports.c_str(), std::ios::binary);
	readReportsFromBinaryFile(ifs_rep);
	ifs_rep.close();

	std::ifstream ifs_chall(bin_challenges.c_str(), std::ios::binary);
	readChallengesFromBinaryFile(ifs_chall);
	ifs_chall.close();

	std::ifstream ifs_users(bin_users.c_str(), std::ios::binary);
	readUsersFromBinaryFile(ifs_users);
	ifs_users.close();

	std::ifstream ifs_pend(bin_pending.c_str(), std::ios::binary);
	readPendingFromBinaryFile(ifs_pend);
	ifs_pend.close();

	std::ifstream ifs_quiz(bin_quizzes.c_str(), std::ios::binary);
	readQuizzesFromBinaryFile(ifs_quiz);
	ifs_quiz.close();
}

void System::setChallenges()
{
	ChallengeType type = ChallengeType::CreatedQuizes;
	Challenge* c = new Challenge(type, 5);
	allChallenges.push_back(std::move(*c));

	type = ChallengeType::SolvingInTestMode;
	Challenge* t = new Challenge(type, 5);
	allChallenges.push_back(std::move(*t));

	type = ChallengeType::SolvingInNormalMode;
	Challenge* n = new Challenge(type, 5);
	allChallenges.push_back(std::move(*n));
}

void System::signUp(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, const MyString& password2)
{
	if (name.getSize() == 0 || familyName.getSize() == 0 || username.getSize() == 0 || password.getSize() == 0)
		throw std::invalid_argument("All fields must be filled!");

	int index = findUserByNickname(username);
	if (index != -1) throw std::invalid_argument("User with this username exists!");
	if (password != password2) throw std::invalid_argument("Passwords must match!");

	Player* player = new Player(name, familyName, username, password);
	allUsers.push_back(player);
}

void System::viewProfile() const
{
	dynamic_cast<Player*>(loggedUser)->viewProfile(allQuizzes);
}

void System::view(const MyString& nickname) const
{
	if (loggedUser->getUserType() != UserType::Player)
	{
		throw std::logic_error("Only players can view profiles!");
	}

	int index = findUserByNickname(nickname);
	if (index == -1) {
		std::cout << "User not found.\n";
		return;
	}

	dynamic_cast<Player*>(allUsers[index])->viewProfile(allQuizzes);
}

void System::viewChallenges() const
{
	for (size_t i = 0; i < allChallenges.getSize(); i++)
	{
		allChallenges[i].print();
	}
}

void System::viewFinishedChallenges() const
{
	Player* player = dynamic_cast<Player*>(loggedUser);
	player->viewFinishedChallenges(allChallenges);
}

void System::messages() const
{
	for (size_t i = 0; i < allMessages.getSize(); i++)
	{
		allMessages[i].printMessage();
	}
}

void System::createQuiz()
{
	/*if (loggedUser->getUserType() != UserType::Player)
	{
		throw std::logic_error("Only players can create quizzes!");
	}*/
	
	MyString title;
	std::cout << "Enter quiz title: ";
	std::cin >> title;
	Quiz quiz(title);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	unsigned num;
	std::cout << "Enter number of questions: ";

	std::cin >> num;

	for (size_t i = 0; i < num; i++)
	{
		std::cout << "Enter question " << i + 1 << " type: ";
		MyString type, description;
		unsigned points;
		std::cin >> type;
		std::cin >> description;
		if (type == "SC")
		{
			MyString ans1, ans2, ans3, ans4;
			char right;
			std::cout << "Enter answer A. ";
			std::cin >> ans1;
			std::cout << "Enter answer B. ";
			std::cin >> ans2;
			std::cout << "Enter answer C. ";
			std::cin >> ans3;
			std::cout << "Enter answer D. ";
			std::cin >> ans4;
			std::cout << "Enter correct answer (A, B, C, D): ";
			std::cin >> right;
			std::cout << "Enter points: ";
			std::cin >> points;
			SingleChoiceQuestion* question = new SingleChoiceQuestion(description, points, ans1, ans2, ans3, ans4, right);
			quiz.addQuestion(question);
		}
		else if (type == "ShA")
		{
			MyString ans;
			std::cout << "Enter correct answer: ";
			std::cin >> ans;
			std::cout << "Enter points: ";
			std::cin >> points;
			ShortAnswerQuestion* question = new ShortAnswerQuestion(description, points, ans);
			quiz.addQuestion(question);
		}
		else if (type == "MC")
		{
			std::cout << "Enter possible answers count: ";
			unsigned cnt;
			std::cin >> cnt;
			MyVector<MyString> options;
			MyVector<char> answers;
			
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			for (size_t i = 0; i < cnt; i++)
			{
				char letter = 'A' + i;
				MyString temp;
				std::cout << "Enter answer " << letter << ": ";
				std::cin >> temp;
				options.push_back(std::move(temp));
			}
			std::cout << "Enter correct answers: ";
			MyString ans;
			std::cin >> ans;
			ans = Helpers::normalize(ans);
			std::stringstream ss(ans.c_str());
			std::string token;

			while (std::getline(ss, token, ','))
			{
				char option = Helpers::getLetter(token.c_str());
				answers.push_back(option);
			}

			std::cout << "Enter points: ";
			std::cin >> points;
			MultipleChoiceQuestion* question = new MultipleChoiceQuestion(description, points, options, answers);
			quiz.addQuestion(question);
		}
		else if (type == "MP")
		{
			unsigned leftNum, rightNum;
			MyVector<MyString> left, right;
			std::cout << "Enter left column values count: ";
			std::cin >> leftNum;
			for (size_t i = 0; i < leftNum; i++)
			{
				char letter = 'A' + i;
				std::cout << "Enter value " << letter << ": ";
				MyString value;
				std::cin >> value;
				left.push_back(std::move(value));
			}

			std::cout << "Enter right column values count: ";
			std::cin >> rightNum;
			for (size_t i = 0; i < rightNum; i++)
			{
				char letter = 'a' + i;
				std::cout << "Enter value " << letter << ": ";
				MyString value;
				std::cin >> value;
				right.push_back(std::move(value));
			}

			std::cout << "Enter correct pairs: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::string tempLine;
			std::getline(std::cin, tempLine);
			MyString input(tempLine.c_str());

			const char* cstr = input.c_str();
			size_t len = input.getSize();
			size_t i = 0;
			MyVector<Pair> answers;

			while (i < len)
			{
				while (i < len && cstr[i] != '(') i++;

				if (i >= len) break;

				i++;
				MyString pairContent;

				while (i < len && cstr[i] != ')')
				{
					if (cstr[i] != ' ')
						pairContent += cstr[i];

					i++;
				}


				if (i >= len || cstr[i] != ')')
				{
					std::cout << "Invalid format: missing ')' in input.\n";
					return;
				}

				i++;

				Pair p = Helpers::getPair(pairContent.c_str());
				answers.push_back(p);
			}

			
			std::cout << "Enter points: ";
			std::cin >> points;
			MatchingPairsQuestion* question = new MatchingPairsQuestion(description, points, left, right, answers);
			quiz.addQuestion(question);
		}
		else if (type == "T/F")
		{
			std::cout << "Enter correct answer (True/False): ";
			bool ans;
			std::cin >> ans;
			std::cout << "Enter points: ";
			std::cin >> points;
			TrueOrFalseQuestion* question = new TrueOrFalseQuestion(description, points, ans);
			quiz.addQuestion(question);
		}
		else
		{
			throw std::invalid_argument("Invalid type!");
		}
	}
	pendingQuizzes.push_back(quiz);
}

void System::quizzes() const
{
	for (size_t i = 0; i < allQuizzes.getSize(); i++)
	{
		allQuizzes[i].displayQuiz();
	}
}

void System::quizzes(const MyString& username) const
{
	for (size_t i = 0; i < allQuizzes.getSize(); i++)
	{
		if (allQuizzes[i].getCreaterUsername() == username)
		{
			allQuizzes[i].displayQuiz();
		}
	}
}

void System::likeQuiz(unsigned quizId)
{
	int index = findQuizById(quizId);
	if (index == -1)
	{
		throw std::invalid_argument("Invalid id!");
	}
	else
	{
		allQuizzes[index].like();
		if (loggedUser->getUserType() == UserType::Player)
		{
			dynamic_cast<Player*>(loggedUser)->likeQuiz(quizId);
		}
		else
		{
			throw std::logic_error("Only players can like quizzes!");
		}
	}
}

void System::unlikeQuiz(unsigned quizId)
{
	int index = findQuizById(quizId);
	if (index == -1)
	{
		throw std::invalid_argument("Invalid id!");
	}
	else
	{
		allQuizzes[index].unlike();
		if (loggedUser->getUserType() == UserType::Player)
		{
			dynamic_cast<Player*>(loggedUser)->unlikeQuiz(quizId);
		}
		else
		{
			throw std::logic_error("Only players can unlike quizzes!");
		}
	}
}

void System::addToFavs(unsigned quizId)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		dynamic_cast<Player*>(loggedUser)->addToFavs(quizId);
	}
	else
	{
		throw std::logic_error("Only players can add quizzes to favourites!");
	}
}

void System::removeFromFavs(unsigned quizId)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		dynamic_cast<Player*>(loggedUser)->removeFromFavs(quizId);
	}
	else
	{
		throw std::logic_error("Only players can remove quizzes from favourites!");
	}
}

void System::startQuiz_normal(unsigned quizId, bool shuffle)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		int index = findQuizById(quizId);
		if(index != -1)
		{
			if (shuffle)
				allQuizzes[index].shuffle();

			allQuizzes[index].setWorkMode(WorkMode::Normal);

			allQuizzes[index].play();
			int points = allQuizzes[index].getCollectedPoints();

			Player* player = dynamic_cast<Player*>(loggedUser);
			player->getPointsNormal(points);
			int count = player->getQuizzesInNormalMode();
			if (count % 5 == 0)
			{
				const Challenge* c = findChallenge(count, ChallengeType::SolvingInNormalMode);
				player->finishChallenge(c->getId());
			}
		}
		else
		{
			throw std::invalid_argument("Invalid id!");
		}
	}
	else
	{
		throw std::logic_error("Only players can start quizzes!");
	}
}

void System::startQuiz_test(unsigned quizId, bool shuffle)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		int index = findQuizById(quizId);
		if (index != -1)
		{
			if (shuffle)
				allQuizzes[index].shuffle();

			allQuizzes[index].setWorkMode(WorkMode::Test);

			allQuizzes[index].play();

			Player* player = dynamic_cast<Player*>(loggedUser);
			player->getPointsTest();
			int count = player->getQuizzesInTestMode();
			if (count % 5 == 0)
			{
				const Challenge* c = findChallenge(count, ChallengeType::SolvingInTestMode);
				player->finishChallenge(c->getId());
				std::cout << c->getText() << c->getPoints() << " points collected!";
			}
		}
		else
		{
			throw std::invalid_argument("Invalid id!");
		}
	}
	else
	{
		throw std::logic_error("Only players can start quizzes!");
	}
}

void System::saveQuiz(unsigned quizId, const MyString& filepath)
{
	std::ofstream ofs(filepath.c_str());

	if (!ofs.is_open())
	{
		std::cout << "Failed to open file for writing: " << filepath << '\n';
		return;
	}

	int index = findQuizById(quizId);
	if(index != -1)
	{
		allQuizzes[index].saveToFile(ofs);
	}
	else
	{
		throw std::invalid_argument("Invalid id!");
	}

	ofs.close();
}

void System::reportQuiz(unsigned quizId, const MyString& reason)
{
	if(loggedUser->getUserType() == UserType::Player)
	{
		int index = findQuizById(quizId);
		if (index == -1) throw std::invalid_argument("Invalid id");

		Report* report = new Report(loggedUser->getUsername(), allQuizzes[index].getCreaterUsername(), quizId, reason);
		reports.push_back(*report);
	}
	else
	{
		throw std::logic_error("Only players can report quizzes!");
	}
}

int System::findQuizById(unsigned id) const
{
	for (size_t i = 0; i < allQuizzes.getSize(); i++)
	{
		if (allQuizzes[i].getId() == id)
			return static_cast<int>(i);
	}

	return -1;
}

int System::findPendingQuizById(unsigned id) const
{
	for (size_t i = 0; i < pendingQuizzes.getSize(); i++)
	{
		if (pendingQuizzes[i].getId() == id)
			return i;
	}

	return -1;
}

int System::findUserByNickname(const MyString& nickname) const
{
	for (size_t i = 0; i < allUsers.getSize(); i++)
	{
		if (allUsers[i]->getUsername() == nickname)
			return i;
	}

	return -1;
}

const Challenge* System::findChallenge(int count, ChallengeType type)
{
	for (size_t i = 0; i < allChallenges.getSize(); ++i)
	{
		if (allChallenges[i].getCount() == count && allChallenges[i].getChallengeType() == type)
			return &allChallenges[i];
	}
	
	Challenge* challenge = new Challenge(type, count);
	allChallenges.push_back(*challenge);
	return challenge;
}

bool System::challengeExists(unsigned id) const
{
	for (size_t i = 0; i < allChallenges.getSize(); ++i)
	{
		if (allChallenges[i].getId() == id)
			return true;
	}
	return false;
}

System::~System()
{
	saveToBinaryFile();
	for (size_t i = 0; i < allUsers.getSize(); i++)
		delete allUsers[i];// without for..
}

void System::saveMessagesToBinaryFile(std::ofstream& ofs) const
{
	size_t size = allMessages.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		allMessages[i].saveToBinaryFile(ofs);
	}
}

void System::saveQuizzesToBinaryFile(std::ofstream& ofs) const
{
	size_t size = allQuizzes.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		allQuizzes[i].saveToBinaryFile(ofs);
	}
}

void System::saveUsersToBinaryFile(std::ofstream& ofs) const
{
	size_t size = allUsers.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		UserType type = allUsers[i]->getUserType();
		ofs.write((const char*)&type, sizeof(type)); 
		allUsers[i]->saveToBinaryFile(ofs);
	}
}

void System::savePendingToBinaryFile(std::ofstream& ofs) const
{
	size_t size = pendingQuizzes.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		pendingQuizzes[i].saveToBinaryFile(ofs);
	}
}

void System::saveReportsToBinaryFile(std::ofstream& ofs) const
{
	size_t size = reports.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		reports[i].saveToBinaryFile(ofs);
	}
}

void System::saveChallengesToBinaryFile(std::ofstream& ofs) const
{
	size_t size = allChallenges.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		allChallenges[i].saveToBinaryFile(ofs);
	}
}

void System::readMessagesFromBinaryFile(std::ifstream& ifs)
{
	allMessages.clear();
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		Message* m = new Message;
		m->readFromBinaryFile(ifs);
		allMessages.push_back(std::move(*m));
	}
}

void System::readReportsFromBinaryFile(std::ifstream& ifs)
{
	reports.clear();
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		Report* r = new Report;
		r->readFromBinaryFile(ifs);
		reports.push_back(std::move(*r));
	}
}

void System::readChallengesFromBinaryFile(std::ifstream& ifs)
{
	allChallenges.clear();
	setChallenges();
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		Challenge* c = new Challenge;
		c->readFromBinaryFile(ifs);

		if (!challengeExists(c->getId()))
			allChallenges.push_back(std::move(*c));
	}
}

void System::readUsersFromBinaryFile(std::ifstream& ifs)
{
	allUsers.clear();
	size_t size;
	ifs.read((char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++)
	{
		UserType type;
		ifs.read((char*)&type, sizeof(type)); 

		User* u = nullptr;

		if (type == UserType::Player)
			u = new Player();
		else if (type == UserType::Admin)
			u = new Administrator();
		else
			throw std::runtime_error("Unknown user type.");

		/*switch (type)
		{
		case UserType::Player:
			u = new Player(); 
			break;
		case UserType::Admin:
			u = new Administrator();
			break;
		default:
			throw std::logic_error("Unknown user type while reading from file");
		}*/

		u->readFromBinaryFile(ifs);
		allUsers.push_back(u);
	}
}

void System::readPendingFromBinaryFile(std::ifstream& ifs)
{
	pendingQuizzes.clear();
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		Quiz* q = new Quiz;
		q->readFromBinaryFile(ifs);
		pendingQuizzes.push_back(std::move(*q));
	}
}

void System::readQuizzesFromBinaryFile(std::ifstream& ifs)
{
	allQuizzes.clear();
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		Quiz* q = new Quiz;
		q->readFromBinaryFile(ifs);
		allQuizzes.push_back(std::move(*q));
	}
}

System& System::getInstance()
{
	static System instance;
	return instance;
}

void System::login(const MyString& username, const MyString& password)
{
	if (loggedUser != nullptr) throw std::logic_error("Another user logged!");

	int index = findUserByNickname(username);
	if (index == -1) throw std::invalid_argument("Invalid username");
	if (allUsers[index]->checkPassword(password))
		loggedUser = allUsers[index];
	else
		throw std::invalid_argument("Wrong password!");
	
}

void System::logout()
{
	loggedUser = nullptr;
}

void System::quit()
{
	saveToBinaryFile();
}

void System::pending() const
{
	if (loggedUser->getUserType() != UserType::Admin)
	{
		throw std::logic_error("Only administrators can access pending quizzes!");
	}

	for (size_t i = 0; i < pendingQuizzes.getSize(); i++)
	{
		pendingQuizzes[i].displayPendingQuiz();
	}
}

void System::approveQuiz(unsigned quizId)
{
	if (loggedUser->getUserType() == UserType::Admin)
	{
		int index = findPendingQuizById(quizId);
		allQuizzes.push_back(std::move(pendingQuizzes[index]));
		MyString username = pendingQuizzes[index].getCreaterUsername();
		std::swap(pendingQuizzes[index], pendingQuizzes[pendingQuizzes.getSize() - 1]);
		pendingQuizzes.pop_back();

		int idx = findUserByNickname(username);
		Player* player = dynamic_cast<Player*>(allUsers[idx]);
		//Player* player = dynamic_cast<Player*>(loggedUser);
		if(player)
		{
			player->createQuiz(quizId);
			int count = player->getCreatedQuizzes();
			if (count % 5 == 0)
			{
				const Challenge* c = findChallenge(count, ChallengeType::CreatedQuizes);
				player->finishChallenge(c->getId());
			}
		}
	}
	else
	{
		throw std::logic_error("Only administrators can approve quizzes!");
	}
}

void System::rejectQuiz(unsigned quizId, const MyString& reasoh)
{
	if (loggedUser->getUserType() == UserType::Admin)
	{
		unsigned index = findPendingQuizById(quizId);
		std::swap(pendingQuizzes[index], pendingQuizzes[pendingQuizzes.getSize() - 1]);
		pendingQuizzes.pop_back();
	}
	else
	{
		throw std::logic_error("Only administrators can reject quizzes!");
	}
}

void System::viewReports() const
{
	if (loggedUser->getUserType() == UserType::Admin)
	{
		for (size_t i = 0; i < reports.getSize(); i++)
		{
			reports[i].print();
		}
	}
	else
	{
		throw std::logic_error("Only administrators can access reports!");
	}
}

void System::removeQuiz(unsigned quizId, MyString& reason)
{
	if (loggedUser->getUserType() == UserType::Admin)
	{
		unsigned index = findQuizById(quizId);
		std::swap(allQuizzes[index], allQuizzes[allQuizzes.getSize() - 1]);
		allQuizzes.pop_back();
	}
	else
	{
		throw std::logic_error("Only administrators can remove quizzes!");
	}
}

void System::ban(const MyString& username) 
{
	if (loggedUser->getUserType() == UserType::Admin)
	{
		if (username == loggedUser->getUsername()) throw std::logic_error("You cannot ban yourself.");
	
		int index = findUserByNickname(username);
		if (index == -1) throw std::logic_error("User not found!");

		delete allUsers[index];//???? no 
		std::swap(allUsers[index], allUsers[allUsers.getSize() - 1]);
		allUsers.pop_back();
	}
	else
	{
		throw std::logic_error("Only administrators can ban users!");
	}
}

//void System::readChallengesFromBinaryFile()
//{
//	setChallenges();
//	//logic
//}

