#pragma once
#include <iostream>
#include "MyString.h"

class Pair 
{
private:
	MyString lhs, rhs;
public:
	Pair() = default;
	Pair(const MyString& lhs, const MyString& rhs);
	
	std::ostream& operator<<(std::ostream& os) const;
	std::istream& operator>>(std::istream& is);
	
	friend bool operator==(const Pair& l, const Pair& r);
};

