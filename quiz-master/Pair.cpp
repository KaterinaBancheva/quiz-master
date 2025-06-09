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

std::ostream& Pair::operator<<(std::ostream& os) const
{
	os << "( " << lhs << ", " << rhs << " )";
	return os;
}

