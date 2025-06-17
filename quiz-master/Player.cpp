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
	points = 0;
	level = 0;
}

Player::Player(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password)
	:User(name, familyName, username, password) 
{
	type = UserType::Player;
	points = 0;
	level = 0;
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
	std::cout << "Points: " << points << "\nLevel: " << level << '\n';
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

	std::cout << "Quiz " << quizId << " added to favourites!\n";
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
		std::cout << "Quiz " << quizId << " removed from favourites!\n";
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
	std::cout << c->getMessage() << "\n";
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

	ofs.write((const char*)&points, sizeof(points));

	size_t sizeLiked = liked.getSize();
	ofs.write((const char*)&sizeLiked, sizeof(size_t));
	for (size_t i = 0; i < sizeLiked; i++)
	{
		unsigned index = liked[i];
		ofs.write((const char*)&index, sizeof(index));
	}

	size_t sizeFav = favourites.getSize();
	ofs.write((const char*)&sizeFav, sizeof(size_t));
	for (size_t i = 0; i < sizeFav; i++)
	{
		unsigned index = favourites[i];
		ofs.write((const char*)&index, sizeof(index));
	}

	ofs.write((const char*)&level, sizeof(level));

	size_t sizeCreated = createdQuizes.getSize();
	ofs.write((const char*)&sizeCreated, sizeof(size_t));
	for (size_t i = 0; i < sizeCreated; i++)
	{
		unsigned index = createdQuizes[i];
		ofs.write((const char*)&index, sizeof(index));
	}
	
	size_t sizeChall = challenges.getSize();
	ofs.write((const char*)&sizeChall, sizeof(size_t));
	for (size_t i = 0; i < sizeChall; i++)
	{
		challenges[i].saveToBinaryFile(ofs);
	}

	ofs.write((const char*)&quizzesInNormalMode, sizeof(unsigned));
	ofs.write((const char*)&quizzesInTestMode, sizeof(unsigned));
}

void Player::readFromBinaryFile(std::ifstream& ifs)
{
	ifs.read((char*)&type, sizeof(type));
	name.read(ifs);
	familyName.read(ifs);
	username.read(ifs);
	password.read(ifs);

	liked.clear();
	favourites.clear();
	createdQuizes.clear();
	challenges.clear();

	ifs.read((char*)&points, sizeof(points));

	size_t sizeLiked;
	ifs.read((char*)&sizeLiked, sizeof(size_t));
	for (size_t i = 0; i < sizeLiked; i++)
	{
		unsigned index;
		ifs.read((char*)&index, sizeof(index));
		liked.push_back(index);
	}

	size_t sizeFav;
	ifs.read((char*)&sizeFav, sizeof(size_t));
	for (size_t i = 0; i < sizeFav; i++)
	{
		unsigned index;
		ifs.read((char*)&index, sizeof(index));
		favourites.push_back(index);
	}

	ifs.read((char*) & level, sizeof(level));

	size_t sizeCreated;
	ifs.read((char*)&sizeCreated, sizeof(size_t));
	for (size_t i = 0; i < sizeCreated; i++)
	{
		unsigned index;
		ifs.read((char*)&index, sizeof(index));
		createdQuizes.push_back(index);
	}

	size_t sizeChall;
	ifs.read((char*)&sizeChall, sizeof(size_t));
	for (size_t i = 0; i < sizeChall; i++)
	{
		PersonalChallenge ch;
		ch.readFromBinaryFile(ifs); 
		challenges.push_back(ch);
	}

	ifs.read((char*)&quizzesInNormalMode, sizeof(unsigned));
	ifs.read((char*)&quizzesInTestMode, sizeof(unsigned));
}
