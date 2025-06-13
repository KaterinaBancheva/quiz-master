#include "Helpers.h"


char Helpers::getLetter(const char* str)
{
	if (!str) return '\0';

	char result = 0;
	size_t i = 0;

	while (str[i] == ' ') i++;

	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		result = str[i];
		return result;
	}

	return '\0';
}

Pair Helpers::getPair(const char* str)
{
	if (!str) return Pair(" ", " ");

	MyString input(str);
	bool parsingLhs = true;

	MyString lhs, rhs;
	size_t i = 0;

	if (input[0] == '(') i++;

	while (input[i])
	{
		if (input[i] == ',')
		{
			parsingLhs = false;
			i++;
			continue;
		}
		if (input[i] == ' ' || input[i] == ')')
		{
			i++;
			continue;
		}
		if (parsingLhs)
		{
			lhs += input[i];
		}
		else
		{
			rhs += input[i];
		}
		i++;
	}

	return Pair(lhs, rhs);
}

MyVector<unsigned> Helpers::shuffleArray(size_t size) 
{
	MyVector<unsigned> indexes;
	for (size_t i = 0; i < size; i++)
	{
		indexes.push_back(i);
	}

	while (size > 1)
	{
		unsigned index = rand() % size;
		std::swap(indexes[index], indexes[size - 1]);
		size--;
	}

	return indexes;
}

int Helpers::contains(unsigned id, MyVector<unsigned> vector)
{
	for (size_t i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] == id)
			return i;
	}

	return -1;
}

MyString Helpers::normalize(const MyString& str)
{
	MyString toReturn = str;

	int i = 0;
	while (toReturn[i])
	{
		if (toReturn[i] >= 'a' && toReturn[i] <= 'z')
		{
			//toReturn[i] = std::toupper(toReturn[i]);
			toReturn[i] = 'A' + toReturn[i] - 'a';
		}
		i++;
	}

	return toReturn;
}

