#include "System.h"
#include <sstream>
#include <iostream>

void System::viewProfile() const
{
	loggedUser->viewProfile();
}

void System::view(const MyString& nickname) const
{
	int index = findUserByNickname(nickname);
}

void System::messages() const
{
	for (size_t i = 0; i < allMessages.getSize(); i++)
	{
		allMessages[i].printMessage();
	}
}

void System::createQuiz()
{
	/*if (loggedUser->getUserType() != UserType::Player)
	{
		throw std::logic_error("Only players can create quizzes!");
	}*/
	
	MyString title;
	std::cout << "Enter quiz title: ";
	std::cin >> title;
	Quiz quiz(title);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	unsigned num;
	std::cout << "Enter number of questions: ";

	std::cin >> num;

	for (size_t i = 0; i < num; i++)
	{
		std::cout << "Enter question " << i + 1 << " type: ";
		MyString type, description;
		unsigned points;
		std::cin >> type;
		std::cin >> description;
		if (type == "SC")
		{
			MyString ans1, ans2, ans3, ans4;
			char right;
			std::cout << "Enter answer A. ";
			std::cin >> ans1;
			std::cout << "Enter answer B. ";
			std::cin >> ans2;
			std::cout << "Enter answer C. ";
			std::cin >> ans3;
			std::cout << "Enter answer D. ";
			std::cin >> ans4;
			std::cout << "Enter correct answer (A, B, C, D): ";
			std::cin >> right;
			std::cout << "Enter points: ";
			std::cin >> points;
			SingleChoiceQuestion* question = new SingleChoiceQuestion(description, points, ans1, ans2, ans3, ans4, right);
			quiz.addQuestion(question);
		}
		else if (type == "ShA")
		{
			MyString ans;
			std::cout << "Enter correct answer: ";
			std::cin >> ans;
			std::cout << "Enter points: ";
			std::cin >> points;
			ShortAnswerQuestion* question = new ShortAnswerQuestion(description, points, ans);
			quiz.addQuestion(question);
		}
		else if (type == "MC")
		{
			std::cout << "Enter possible answers count: ";
			unsigned cnt;
			std::cin >> cnt;
			MyVector<MyString> options;
			MyVector<char> answers;
			
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			for (size_t i = 0; i < cnt; i++)
			{
				char letter = 'A' + i;
				MyString temp;
				std::cout << "Enter answer " << letter << ": ";
				std::cin >> temp;
				options.push_back(std::move(temp));
			}
			std::cout << "Enter correct answers: ";
			MyString ans;
			std::cin >> ans;
			ans = Helpers::normalize(ans);
			std::stringstream ss(ans.c_str());
			std::string token;

			while (std::getline(ss, token, ','))
			{
				char option = Helpers::getLetter(token.c_str());
				answers.push_back(option);
			}

			std::cout << "Enter points: ";
			std::cin >> points;
			MultipleChoiceQuestion* question = new MultipleChoiceQuestion(description, points, options, answers);
			quiz.addQuestion(question);
		}
		else if (type == "MP")
		{
			unsigned leftNum, rightNum;
			MyVector<MyString> left, right;
			std::cout << "Enter left column values count: ";
			std::cin >> leftNum;
			for (size_t i = 0; i < leftNum; i++)
			{
				char letter = 'A' + i;
				std::cout << "Enter value " << letter << ": ";
				MyString value;
				std::cin >> value;
				left.push_back(std::move(value));
			}

			std::cout << "Enter right column values count: ";
			std::cin >> rightNum;
			for (size_t i = 0; i < rightNum; i++)
			{
				char letter = 'a' + i;
				std::cout << "Enter value " << letter << ": ";
				MyString value;
				std::cin >> value;
				right.push_back(std::move(value));
			}

			std::cout << "Enter correct pairs: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::string tempLine;
			std::getline(std::cin, tempLine);
			MyString input(tempLine.c_str());

			const char* cstr = input.c_str();
			size_t len = input.getSize();
			size_t i = 0;
			MyVector<Pair> answers;

			while (i < len)
			{
				while (i < len && cstr[i] != '(') i++;

				if (i >= len) break;

				i++;
				MyString pairContent;

				while (i < len && cstr[i] != ')')
				{
					if (cstr[i] != ' ')
						pairContent += cstr[i];

					i++;
				}


				if (i >= len || cstr[i] != ')')
				{
					std::cout << "Invalid format: missing ')' in input.\n";
					return;
				}

				i++;

				Pair p = Helpers::getPair(pairContent.c_str());
				answers.push_back(p);
			}

			
			std::cout << "Enter points: ";
			std::cin >> points;
			MatchingPairsQuestion* question = new MatchingPairsQuestion(description, points, left, right, answers);
			quiz.addQuestion(question);
		}
		else if (type == "T/F")
		{
			std::cout << "Enter correct answer (True/False): ";
			bool ans;
			std::cin >> ans;
			std::cout << "Enter points: ";
			std::cin >> points;
			TrueOrFalseQuestion* question = new TrueOrFalseQuestion(description, points, ans);
			quiz.addQuestion(question);
		}
		else
		{
			throw std::invalid_argument("Invalid type!");
		}
	}
	allQuizzes.push_back(quiz);
}

void System::quizzes() const
{
	for (size_t i = 0; i < allQuizzes.getSize(); i++)
	{
		allQuizzes[i].displayQuiz();
	}
}

void System::quizzes(const MyString& username) const
{
	for (size_t i = 0; i < allQuizzes.getSize(); i++)
	{
		if (allQuizzes[i].getCreaterUsername() == username)
		{
			allQuizzes[i].displayQuiz();
		}
	}
}

void System::likeQuiz(unsigned quizId)
{
	int index = findQuizById(quizId);
	if (index == -1)
	{
		throw std::invalid_argument("Invalid id!");
	}
	else
	{
		allQuizzes[index].like();
		if (loggedUser->getUserType() == UserType::Player)
		{
			dynamic_cast<Player*>(loggedUser)->likeQuiz(quizId);
		}
		else
		{
			throw std::logic_error("Only players can like quizzes!");
		}
	}
}

void System::unlikeQuiz(unsigned quizId)
{
	int index = findQuizById(quizId);
	if (index == -1)
	{
		throw std::invalid_argument("Invalid id!");
	}
	else
	{
		allQuizzes[index].unlike();
		if (loggedUser->getUserType() == UserType::Player)
		{
			dynamic_cast<Player*>(loggedUser)->unlikeQuiz(quizId);
		}
		else
		{
			throw std::logic_error("Only players can unlike quizzes!");
		}
	}
}

void System::addToFavs(unsigned quizId)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		dynamic_cast<Player*>(loggedUser)->addToFavs(quizId);
	}
	else
	{
		throw std::logic_error("Only players can add quizzes to favourites!");
	}
}

void System::removeFromFavs(unsigned quizId)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		dynamic_cast<Player*>(loggedUser)->removeFromFavs(quizId);
	}
	else
	{
		throw std::logic_error("Only players can remove quizzes from favourites!");
	}
}

void System::startQuiz_normal(unsigned quizId, bool shuffle)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		int index = findQuizById(quizId);
		if(index != -1)
		{
			if (shuffle)
				allQuizzes[index].shuffle();

			allQuizzes[index].setWorkMode(WorkMode::Normal);

			allQuizzes[index].play();
		}
		else
		{
			throw std::invalid_argument("Invalid id!");
		}
	}
	else
	{
		throw std::logic_error("Only players can start quizzes!");
	}
}

void System::startQuiz_test(unsigned quizId, bool shuffle)
{
	if (loggedUser->getUserType() == UserType::Player)
	{
		int index = findQuizById(quizId);
		if (index != -1)
		{
			if (shuffle)
				allQuizzes[index].shuffle();

			allQuizzes[index].setWorkMode(WorkMode::Test);

			allQuizzes[index].play();
		}
		else
		{
			throw std::invalid_argument("Invalid id!");
		}
	}
	else
	{
		throw std::logic_error("Only players can start quizzes!");
	}
}

int System::findQuizById(unsigned id) const
{
	for (size_t i = 0; i < allQuizzes.getSize(); i++)
	{
		if (allQuizzes[i].getId() == id)
			return i;
	}

	return -1;
}

int System::findUserByNickname(const MyString& nickname) const
{
	for (size_t i = 0; i < allUsers.getSize(); i++)
	{
		if (allUsers[i]->getUsername() == nickname)
			return i;
	}

	return -1;
}
