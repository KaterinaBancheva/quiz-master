#include "Pair.h"

bool operator==(const Pair& l, const Pair& r)
{
	return l.lhs == r.lhs && l.rhs == r.rhs;
}

Pair::Pair(const MyString& lhs, const MyString& rhs)
{
	this->lhs = lhs;
	this->rhs = rhs;
}

std::ostream& operator<<(std::ostream& os, const Pair& obj)
{
	os << "( " << obj.lhs << ", " << obj.rhs << " )";
	return os;
}

std::istream& operator>>(std::istream& is, Pair& obj)
{
	char ch;
	MyString lhs, rhs;

	is >> ch;        
	if (ch != '(') {
		is.setstate(std::ios::failbit);
		return is;
	}

	is >> lhs;

	is >> ch;          
	if (ch != ',') {
		is.setstate(std::ios::failbit);
		return is;
	}

	is >> rhs;

	is >> ch;          
	if (ch != ')') {
		is.setstate(std::ios::failbit);
		return is;
	}

	obj.lhs = lhs;
	obj.rhs = rhs;
	return is;
}

