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

	void setLhs(const MyString& str);
	void setRhs(const MyString& str);
	
	friend std::ostream& operator<<(std::ostream& os, const Pair& obj);
	friend std::istream& operator>>(std::istream& is, Pair& obj);
	
	friend bool operator==(const Pair& l, const Pair& r);

	void saveToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);
};

