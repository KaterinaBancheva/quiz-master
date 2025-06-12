#include <iostream>
#include "SingleChoiceQuestion.h"
#include "ShortAnswerQuestion.h"
#include "TrueOrFalseQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "Quiz.h"

int main()
{
	std::ofstream ofs ("SAQ.bin", std::ios::binary);

	MyVector<MyString> options;
	options.push_back("L = { a^n | n >= 0 }"); // regular
	options.push_back("L = { a^n b^n | n >= 0 }"); // not regular
	options.push_back("L = { w | w contains equal number of a's and b's }"); // not regular
	options.push_back("L = { a^n b^m | n, m ≥ 0 }"); //  regular
	options.push_back("L = { a^n b^n c^n | n ≥ 0 }"); // not regular
	options.push_back("L = { w ∈ {a, b}* | w contains 'aba' }"); //regular

	MyVector<char> answers;
	answers.push_back('A');
	answers.push_back('D');
	answers.push_back('F');

	MyString description = "Which of the following languages are regular?";
	MultipleChoiceQuestion mp(description, 30, options, answers);
	/*mp.saveToBinaryFile(ofs);

	ofs.close();
	MultipleChoiceQuestion mp1;

	std::ifstream ifs("SAQ.bin", std::ios::binary);
	mp1.readFromBinaryFile(ifs);
	mp1.printNormal();	*/

	std::ofstream offs ("Demo.txt");
	ShortAnswerQuestion saq("Hi", 10, "what");
	SingleChoiceQuestion q("How are you", 10, "fine", "bad", "idk", "great", 'D');
	TrueOrFalseQuestion tf("Ternary operator can be overloaded in C++", 5, 0);
	Quiz q1("quiz1");
	q1.addQuestion(&saq);
	q1.addQuestion(&q);
	q1.addQuestion(&tf);
	q1.addQuestion(&mp);
	q1.play();
	q1.setWorkMode(WorkMode::Test);
	q1.play();
	q1.like();
	q1.unlike();
	q1.saveToFile(offs);
}
