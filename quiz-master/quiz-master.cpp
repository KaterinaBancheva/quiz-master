#include <iostream>
#include "ShortAnswerQuestion.h"
#include "Quiz.h"

int main()
{
	std::ofstream ofs ("SAQ.bin", std::ios::binary);

	ShortAnswerQuestion saq("How are you", 10, "fine");
	saq.saveToBunaryFile(ofs);

	ShortAnswerQuestion saq1(" ", 0, " ");
	ofs.close();

	std::ifstream ifs("SAQ.bin", std::ios::binary);
	saq1.readFromBinaryFile(ifs);
	saq1.printNormal();

	//std::ofstream os ("Demo.txt");
	////saq.saveToFile(os);
	//Quiz q1("quiz1");
	//q1.addQuestion(&saq);
	//q1.play();
	//q1.setWorkMode(WorkMode::Test);
	//q1.play();
	//q1.like();
	//q1.unlike();
	//q1.saveToFile(os);
}
