#pragma once
#include "MyString.h"
#include "Quiz.h"
#include "MyVector.hpp"
#include "Pair.h"

namespace Helpers
{
	MyString normalize(const MyString& str);
	char getLetter(const char* str);

	Pair getPair(const char* str);

	MyVector<unsigned> shuffleArray(size_t size);

	int contains(unsigned id, MyVector<unsigned> vector);
};

