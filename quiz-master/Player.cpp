#include "Player.h"

Player::Player(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, UserType& type)
	:User(name, familyName, username, password) 
{
	this->type = type;
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

UserType Player::getUserType() const
{
	return UserType::Player;
}
