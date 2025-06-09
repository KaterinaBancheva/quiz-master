//#pragma once
//#include"MyVector.hpp"
//#include "Question.h"
//
//constexpr int MIN_ANSWERS_COUNT = 4;
//constexpr int MIN_RIGHT_ANSWERS_COUNT = 2;
//
//class MultipleChoiceQuestion :
//    public Question
//{
//private:
//    unsigned answersCount, rightAnswersQount;
//    MyString rightAnswers;
//    MyVector<MyString> answers;
//public:
//    MultipleChoiceQuestion(const MyString& description, int points, unsigned answersCount, unsigned rightAnswersCount);
//
//    void addAnswer(const MyString& answer);
//    void setRightAnswers(const MyString& rightAnswers);
//
//    Question* clone() const override;
//    void answer() override;
//    void printTest() const override;
//    void printNormal() const override;
//    ~MultipleChoiceQuestion() override = default;
//
//    void saveToFile(std::ofstream& ofs) const override;
//    void saveToBunaryFile(std::ostream& os) const override;
//    void readFromBinaryFile(std::istream& is) override;
//};