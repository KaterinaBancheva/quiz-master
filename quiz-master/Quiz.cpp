#include "Quiz.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
 
unsigned Quiz::counter = 2;
 
void Quiz::free()
{
	for (size_t i = 0; i < questions.getSize(); ++i)
		delete questions[i];

	questions.clear();
}

void Quiz::copyFrom(const Quiz& other)
{
	for (size_t i = 0; i < other.questions.getSize(); ++i)
	{
		questions.push_back(other.questions[i]->clone());
	}
	id = other.id;
	title = other.title;
	questionsCount = other.questionsCount;
	createrNames = other.createrNames;
	createrUsername = other.createrUsername;
	mode = other.mode;
	playsCount = other.playsCount;
	likesCount = other.likesCount;
	collectedPoints = other.collectedPoints;
	shuffleOn = other.shuffleOn;
	liked = other.liked;
}

//Quiz::Quiz()
//{
//	title = " ";
//	createrUsername = " ";
//	id = counter;
//	counter++;
//}

Quiz::Quiz(const MyString& title, const MyString& createrUsername)
{
	this->title = title;
	this->createrUsername = createrUsername;
	id = counter;
	counter++;
}

Quiz::Quiz(const Quiz& other)
{
	copyFrom(other);
}

Quiz& Quiz::operator=(const Quiz& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
		liked = other.liked;
		
	}
	return *this;
}

Quiz::~Quiz()
{
	free();
}

unsigned Quiz::getId() const
{
	return id;
}

const MyString& Quiz::getTitle() const
{
	return title;
}

unsigned Quiz::getQuestionsCount() const
{
	return questionsCount;
}

WorkMode Quiz::getWorkMode() const
{
	return mode;
}

unsigned Quiz::getPlaysCount() const
{
	return playsCount;
}

unsigned Quiz::getLikesCount() const
{
	return likesCount;
}

const MyString& Quiz::getCreaterUsername() const
{
	return createrUsername;
}

int Quiz::getCollectedPoints() const
{
	return collectedPoints;
}

void Quiz::setWorkMode(const WorkMode mode)
{
	this->mode = mode;
}

void Quiz::setNames(const MyString& name, const MyString& family)
{
	createrNames = name;
	createrNames += " ";
	createrNames += family;
}

void Quiz::addQuestion(Question* question)
{
	questions.push_back(question);
	questionsCount++;
}

void Quiz::like()
{
	if (liked == false)
	{
		liked = true;
		likesCount++;
		std::cout << "Quiz with id " << id << " liked \n";
	}
	else
	{
		std::cout << "Quiz with id " << id << " is already liked \n";
	}
}

void Quiz::unlike()
{
	if (liked == true)
	{
		liked = false;
		likesCount--;
		std::cout << "Quiz with id " << id << " unliked \n";
	}
	else
	{
		std::cout << "Quiz with id " << id << " is not liked \n";
	}
}

bool Quiz::isLiked() const
{
	return liked;
}

void Quiz::shuffle()
{
	shuffleOn = true;
	std::cout << "Shuffle mode enabled \n";
}

void Quiz::play()
{
	collectedPoints = 0;
	playsCount++;
	MyVector<unsigned> indexes;
	if (shuffleOn)
	{
		indexes = Helpers::shuffleArray(questions.getSize());
		/*std::cout << "Shuffled indexes: ";
		for (size_t i = 0; i < indexes.getSize(); i++)
		{
			std::cout << indexes[i] << ' ';
		}
		std::cout << '\n';*/
	}
	else
	{
		for (size_t i = 0; i < questions.getSize(); i++)
			indexes.push_back(i);
	}

	if (mode == WorkMode::Normal)
	{
		int sum = 0;
		std::cout << "Play " << title << ": \n";
		for (size_t i = 0; i < questions.getSize(); i++)
		{
			size_t realIndex = indexes[i];
			sum += questions[realIndex]->getQuestionPoints();
			std::cout << "question " << i+1 << ":\n";
			questions[realIndex]->printNormal();
			if (questions[realIndex]->answerNormal())
			{
				collectedPoints += questions[realIndex]->getQuestionPoints();
			}
		}
		std::cout << "Your quiz score is " << collectedPoints <<  '/' << sum <<  '\n';
	}
	else
	{
		std::cout << "Play " << title << ": \n";
		for (size_t i = 0; i < questions.getSize(); i++)
		{
			size_t realIndex = indexes[i];
			std::cout << "question " << i+1 << ":\n";
			questions[realIndex]->printTest();
			questions[realIndex]->answerTest();
		}
	}
	
}

void Quiz::saveToFile(std::ofstream& ofs) const
{
	ofs << title << " - " << questionsCount << " questions \n";
	ofs << "By: " << createrNames << createrUsername << "\n";
	for (size_t i = 0; i < questionsCount; i++)
	{
		ofs << i + 1 << ')';
		questions[i]->saveToFile(ofs);
		ofs << '\n';
	}
}

void Quiz::saveCurrentQuizIdToBinaryFile(std::ofstream& ofs)
{
	ofs.write((const char*)&counter, sizeof(counter));
}

void Quiz::readFromBinaryFile(std::ifstream& ifs)
{
	ifs.read((char*)&id, sizeof(id));
	title.read(ifs);
	ifs.read((char*)&questionsCount, sizeof(questionsCount));
	questions.clear();
	for (size_t i = 0; i < questionsCount; i++)
	{
		Question* q = nullptr;
		QuestionType type;
		ifs.read((char*)&type, sizeof(type));
		switch (type)
		{
		case QuestionType::ShA: q = new ShortAnswerQuestion(); break;
		case QuestionType::SC: q = new SingleChoiceQuestion(); break;
		case QuestionType::MC: q = new MultipleChoiceQuestion(); break;
		case QuestionType::MP: q = new MatchingPairsQuestion(); break;
		case QuestionType::TF: q = new TrueOrFalseQuestion(); break;
		default: throw std::logic_error("Invalid question type!"); break;
		}

		q->readFromBinaryFile(ifs);
		questions.push_back(q);
	}
	createrNames.read(ifs);
	createrUsername.read(ifs);
}

void Quiz::readCurrentQuizIdToBinaryFile(std::ifstream& ifs)
{
	ifs.read((char*)&counter, sizeof(counter));
}

void Quiz::saveToBinaryFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&id, sizeof(id));
	title.write(ofs);
	ofs.write((const char*)&questionsCount, sizeof(questionsCount));
	for (size_t i = 0; i < questionsCount; i++)
	{
		if (!questions[i]) {
			std::cerr << "questions[" << i << "] is null!\n";
			throw std::logic_error("exception..");
		}

		QuestionType type = questions[i]->getType();
		ofs.write((const char*)&type, sizeof(type));
		questions[i]->saveToBinaryFile(ofs);
	}
	createrNames.write(ofs);
	createrUsername.write(ofs);
}

void Quiz::displayQuiz() const
{
	std::cout << title << " - " << questionsCount << " questions \n";
	std::cout << "By: " << createrNames << " " << createrUsername << "\n";
	std::cout << "Likes: " << likesCount << "\n";
	for (size_t i = 0; i < questionsCount; i++)
	{
		std::cout << i + 1 << ')';
		questions[i]->printTest();
		std::cout << '\n';
	}
}

void Quiz::displayPendingQuiz() const
{
	std::cout << "[ id " << id << " ] " << title << " By: " << createrUsername << "\n";
}


