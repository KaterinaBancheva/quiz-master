#include <iostream>
#include "SingleChoiceQuestion.h"
#include "ShortAnswerQuestion.h"
#include "Quiz.h"

int main()
{
	std::ofstream ofs ("SAQ.bin", std::ios::binary);
	/*
	MyString description = "How are you";
	SingleChoiceQuestion q(description, 10, "fine", "bad", "idk", "great", 'D');
	q.saveToBunaryFile(ofs);

	SingleChoiceQuestion q_((const MyString) " ", 0, (MyString)" ", (MyString)" ", (MyString)" ", (MyString)" ", 'A');
	ofs.close();

	std::ifstream ifs("SAQ.bin", std::ios::binary);
	q_.readFromBinaryFile(ifs);
	q_.printNormal();*/

	std::ofstream offs ("Demo.txt");
	ShortAnswerQuestion saq("Hi", 10, "what");
	MyString description = "How are you";
	SingleChoiceQuestion q(description, 10, "fine", "bad", "idk", "great", 'D');
	Quiz q1("quiz1");
	q1.addQuestion(&saq);
	q1.addQuestion(&q);
	q1.play();
	q1.setWorkMode(WorkMode::Test);
	q1.play();
	q1.like();
	q1.unlike();
	q1.saveToFile(offs);
}
