#pragma once
#include "MyString.h"

enum class WorkMode
{
	Normal,
	Test
};
class Quiz
{
	static unsigned counter;
private:
	unsigned id;
	MyString title;
	unsigned questionsQount;

	//right answers ?

	WorkMode mode;
	unsigned playCounts;
	bool shuffle;
	bool like; // when profile
	bool favourites; // when profile
public:
	//void play();
	// get set...
	void like();
	void addToFavourites();
};

