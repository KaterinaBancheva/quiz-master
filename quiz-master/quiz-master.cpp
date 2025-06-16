#include <iostream>
#include <string>
//#include "SingleChoiceQuestion.h"
//#include "ShortAnswerQuestion.h"
//#include "TrueOrFalseQuestion.h"
//#include "MultipleChoiceQuestion.h"
//#include "MatchingPairsQuestion.h"
//#include "Quiz.h"
#include "System.h"
#include "CommandFactory.h"


int main()
{
	//srand(static_cast<unsigned>(time(0)));
	////std::ofstream ofs ("SAQ.bin", std::ios::binary);

	//MyVector<MyString> leftColumn;
	//leftColumn.push_back("Apple");
	//leftColumn.push_back("Car");
	//leftColumn.push_back("Sun");

	//MyVector<MyString> rightColumn;
	//rightColumn.push_back("Fruit");
	//rightColumn.push_back("Vehicle");
	//rightColumn.push_back("Star");

	//MyVector<Pair> correctPairs;
	//correctPairs.push_back(Pair("A", "a"));
	//correctPairs.push_back(Pair("B", "b"));
	//correctPairs.push_back(Pair("C", "c"));

	//MatchingPairsQuestion question("Match the following items correctly.", 5, leftColumn, rightColumn, correctPairs);

	//MyVector<MyString> options;
	//options.push_back("L = { a^n | n >= 0 }"); // regular
	//options.push_back("L = { a^n b^n | n >= 0 }"); // not regular
	//options.push_back("L = { w | w contains equal number of a's and b's }"); // not regular
	//options.push_back("L = { a^n b^m | n, m ≥ 0 }"); //  regular
	//options.push_back("L = { a^n b^n c^n | n ≥ 0 }"); // not regular
	//options.push_back("L = { w ∈ {a, b}* | w contains 'aba' }"); //regular

	//MyVector<char> answers;
	//answers.push_back('A');
	//answers.push_back('D');
	//answers.push_back('F');

	//MyString description = "Which of the following languages are regular?";
	//MultipleChoiceQuestion mp(description, 30, options, answers);

	////question.saveToBinaryFile(ofs);

	////ofs.close();
	////MatchingPairsQuestion question1;

	////std::ifstream ifs("SAQ.bin", std::ios::binary);
	////question1.readFromBinaryFile(ifs);
	////question1.printNormal();

	//std::ofstream offs ("Demo.txt");
	//ShortAnswerQuestion saq("Hi", 10, "what");
	//SingleChoiceQuestion q("How are you", 10, "fine", "bad", "idk", "great", 'D');
	//TrueOrFalseQuestion tf("Ternary operator can be overloaded in C++", 5, 0);
	//Quiz q1("quiz1");
	//q1.addQuestion(&saq);
	//q1.addQuestion(&q);
	//q1.addQuestion(&tf);
	//q1.addQuestion(&mp);
	//q1.addQuestion(&question);
	//q1.setWorkMode(WorkMode::Test);
	////q1.play();
	//q1.shuffle();
	//q1.displayQuiz();
	////q1.play();
	////q1.saveToFile(offs);
	//s.createQuiz();



	//try {
	//	LoginCommand login("@admin_1", "0001");
	//	login.execute();
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what();
	//}

	System& s = System::getInstance();
	
	std::cout << "Welcome to Quiz Master!" << std::endl;

	while (true)
	{
		try
		{
			std::cout << "> ";

			std::string line;
			std::getline(std::cin, line);
			MyString commandLine(line.c_str());

			if (commandLine.getSize() == 0)
			{
				std::cout << "Thank you for using Quiz Master! " << std::endl;
				break;
			}

			Command* cmd = CommandFactory::generateCommand(commandLine);

			if (cmd)
			{
				cmd->execute();

				if (commandLine == "quit")
				{
					std::cout << "Thank you for using Quiz Master! " << std::endl;
					break;
				}

				delete cmd;
			}
		}
		catch (std::invalid_argument& ex) 
		{
			std::cout << ex.what() << "\n";
		}
		catch (std::logic_error& ex) 
		{
			std::cout << ex.what() << "\n";
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << "\n";
		}
	}
}
