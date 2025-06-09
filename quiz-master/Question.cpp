#include "Question.h"

Question::Question(const MyString& description, int points)
{
    this->description = description;
    this->points = points;
}

int Question::getQuestionPoints() const
{
    return points;
}

const MyString& Question::getDescription() const
{
    return description;
}
