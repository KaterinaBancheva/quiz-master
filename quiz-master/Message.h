#pragma once
#pragma warning (disable:4996)
#include "MyString.h"
#include <iostream>
#include <fstream>

class Message
{
private:
	MyString content;
	MyString sender;
	MyString receiver;
	time_t timestamp;

public:
	Message();
	Message(const MyString& content, const MyString& sender, const MyString& receiver);
	void printMessage() const;

	const MyString& getReceiver() const;
	const MyString& getContent() const;

	void saveToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);
};

