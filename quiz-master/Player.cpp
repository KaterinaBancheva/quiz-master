#include "Player.h"

int Player::contains(unsigned id, MyVector<unsigned> vector) const
{
	for (size_t i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] == id)
			return i;
	}
	
	return -1;
}

Player::Player(const MyString& name, const MyString& familyName, const MyString& username, const MyString& password, UserType& type)
	:User(name, familyName, username, password) 
{
	this->type = type;
}

void Player::addToFavs(unsigned quizId)
{
	if(contains(quizId, favourites) == -1)
		favourites.push_back(quizId);
}

void Player::removeFromFavs(unsigned quizId)
{
	unsigned index = contains(quizId, favourites);

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
	if (contains(quizId, liked) == -1)
		liked.push_back(quizId);
}

void Player::unlikeQuiz(unsigned quizId)
{
	unsigned index = contains(quizId, liked);

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

UserType Player::getUserType() const
{
	return UserType::Player;
}
