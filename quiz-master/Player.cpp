#include "Player.h"

bool Player::contains(unsigned id) const
{
	for (size_t i = 0; i < challenges.getSize(); i++)
	{
		if (challenges[i].getChallengeId() == id)
			return true;
	}
	return false;
}

int Player::findQuizById(const MyVector<Quiz>& vector, unsigned id) const
{
	for (size_t i = 0; i < vector.getSize(); i++)
	{
		if (vector[i].getId() == id)
			return static_cast<int>(i);
	}

	return -1;
}

Player::Player() : User(" ", " ", " ", " ")
{
	type = UserType::Player;
}

Player::Player(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password)
	:User(name, familyName, username, password) 
{
	type = UserType::Player;
}

void Player::viewProfile(const MyVector<Quiz>& allQuizzes) const
{
	std::cout << name << ' ' << familyName << ' ' << username << '\n';
	//std::cout << level << "\n\n"
	std::cout << "Created quizzes: \n";
	for (size_t i = 0; i < createdQuizes.getSize(); i++)
	{
		int index = findQuizById(allQuizzes, createdQuizes[i]);
		std::cout << "[ " << createdQuizes[i] << " ] " << allQuizzes[index].getTitle() << '\n';
	}
}

void Player::viewFinishedChallenges(const MyVector<Challenge> allChallenges) const
{
	for (size_t i = 0; i < allChallenges.getSize(); i++)
	{
		int index = contains(allChallenges[i].getId());
		if (index != -1);
		{
			challenges[index].print(&allChallenges[i]);
		}
	}
}

void Player::createQuiz(unsigned id)
{
	createdQuizes.push_back(id);
}

void Player::addToFavs(unsigned quizId)
{
	if(Helpers::contains(quizId, favourites) == -1)
		favourites.push_back(quizId);
}

void Player::removeFromFavs(unsigned quizId)
{
	unsigned index = Helpers::contains(quizId, favourites);

	if (index == -1)
	{
		return;
	}
	else
	{
		std::swap(favourites[index], favourites[favourites.getSize() - 1]);
		favourites.pop_back();
	}
}

void Player::likeQuiz(unsigned quizId)
{
	if (Helpers::contains(quizId, liked) == -1)
		liked.push_back(quizId);
}

void Player::unlikeQuiz(unsigned quizId)
{
	unsigned index = Helpers::contains(quizId, liked);

	if (index == -1)
	{
		return;
	}
	else
	{
		std::swap(liked[index], liked[liked.getSize() - 1]);
		liked.pop_back();
	}
}

void Player::getPointsNormal(int points)
{
	quizzesInNormalMode++;
	this->points += points;
}

void Player::getPointsTest()
{
	quizzesInTestMode++;
}

unsigned Player::getQuizzesInNormalMode() const
{
	return quizzesInNormalMode;
}

unsigned Player::getQuizzesInTestMode() const
{
	return quizzesInTestMode;
}

unsigned Player::getCreatedQuizzes() const
{
	return createdQuizes.getSize();
}

void Player::finishChallenge(unsigned id)
{
	PersonalChallenge* c = new PersonalChallenge(username, id);
	challenges.push_back(*c);
	std::cout << c->getMessage();
}

UserType Player::getUserType() const
{
	return UserType::Player;
}

void Player::saveToBinaryFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&type, sizeof(type));
	name.write(ofs);
	familyName.write(ofs);
	username.write(ofs);
	password.write(ofs);
}

void Player::readFromBinaryFile(std::ifstream& ifs)
{
	ifs.read((char*)&type, sizeof(type));
	name.read(ifs);
	familyName.read(ifs);
	username.read(ifs);
	password.read(ifs);
}
