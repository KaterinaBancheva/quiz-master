#pragma once
#include "MyString.h"
#include "Pair.h"

namespace Helpers
{
	MyString normalize(const MyString& str);
	char getLetter(const char* str);

	Pair getPair(const char* str);
};

