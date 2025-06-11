#include <iostream>
#include "SingleChoiceQuestion.h"
#include "ShortAnswerQuestion.h"
#include "TrueOrFalseQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "Quiz.h"

int main()
{
	std::ofstream ofs ("SAQ.bin", std::ios::binary);
	
	MultipleChoiceQuestion mp("Which of the following languages are regular?", 30, 5, 2, "A,C");
	mp.saveToBinaryFile(ofs);

	ofs.close();
	MultipleChoiceQuestion mp1(" ", 0, 5, 2, " ");

	std::ifstream ifs("SAQ.bin", std::ios::binary);
	mp1.readFromBinaryFile(ifs);
	mp1.printNormal();	

	//std::ofstream offs ("Demo.txt");
	//ShortAnswerQuestion saq("Hi", 10, "what");
	//MyString description = "How are you";
	//SingleChoiceQuestion q(description, 10, "fine", "bad", "idk", "great", 'D');
	//TrueOrFalseQuestion tf("Ternary operator can be overloaded in C++", 5, 0);
	//Quiz q1("quiz1");
	//q1.addQuestion(&saq);
	//q1.addQuestion(&q);
	//q1.addQuestion(&tf);
	//q1.play();
	//q1.setWorkMode(WorkMode::Test);
	//q1.play();
	//q1.like();
	//q1.unlike();
	//q1.saveToFile(offs);
}
