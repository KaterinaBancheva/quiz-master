#include "Quiz.h"
#include <iostream>

Quiz::Quiz(const MyString& title)
{
	this->title = title;
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
	return playCounts;
}

void Quiz::setWorkMode(const WorkMode mode)
{
	this->mode = mode;
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
	if (mode == WorkMode::Normal)
	{
		int sum = 0;
		std::cout << "Play " << title << ": \n";
		for (size_t i = 0; i < questions.getSize(); i++)
		{
			sum += questions[i]->getQuestionPoints();
			std::cout << "question " << i+1 << ":\n";
			questions[i]->printNormal();
			if (questions[i]->answerNormal())
			{
				collectedPoints += questions[i]->getQuestionPoints();
			}
		}
		std::cout << "Your quiz score is " << collectedPoints <<  '/' << sum <<  '\n';
	}
	else
	{
		std::cout << "Play " << title << ": \n";
		for (size_t i = 0; i < questions.getSize(); i++)
		{
			std::cout << "question " << i+1 << ":\n";
			questions[i]->printTest();
			questions[i]->answerTest();
		}
	}
	
}

void Quiz::saveToFile(std::ofstream& ofs) const
{
	ofs << title << " - " << questionsCount << " questions \n";
	ofs << "By: " << createrNames << createrUsername << "\n";
	for (size_t i = 0; i < questionsCount; i++)
	{
		questions[i]->saveToFile(ofs);
	}
}


