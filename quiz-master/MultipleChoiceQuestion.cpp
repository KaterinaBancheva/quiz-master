//#include "MultipleChoiceQuestion.h"
//MultipleChoiceQuestion::MultipleChoiceQuestion(const MyString& description, int points, unsigned answersCount, unsigned rightAnswersCount)
//    :Question(description, points)
//{
//    if (answersCount < MIN_ANSWERS_COUNT || rightAnswersCount < MIN_RIGHT_ANSWERS_COUNT)
//        throw std::invalid_argument("Invalid input!");
//
//    this->answersCount = answersCount;
//    this->rightAnswersQount = rightAnswersCount;
//}
//void MultipleChoiceQuestion::addAnswer(const MyString& answer)
//{
//    answers.push_back(answer);
//}
//void MultipleChoiceQuestion::setRightAnswers(const MyString& rightAnswers)
//{
//    this->rightAnswers = rightAnswers;
//}
//Question* MultipleChoiceQuestion::clone() const
//{
//    return new MultipleChoiceQuestion(*this);
//}
