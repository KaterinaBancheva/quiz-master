#pragma once
#include"MyVector.hpp"
#include "Question.h"

constexpr int MIN_ANSWERS_COUNT = 4;
constexpr int MIN_RIGHT_ANSWERS_COUNT = 2;

class MultipleChoiceQuestion :
    public Question
{
private:
    MyVector<MyString> options;
    MyVector<int> rightAnswers;

    MyString normalize(const MyString& str);
    int toInt(const char* str);
    bool contains(int indx) const;
public:
    MultipleChoiceQuestion(const MyString& description, int points, const MyVector<MyString>& options, const MyVector<int>& rightAnswers);
  
    Question* clone() const override;
    void answerTest() override;
    bool answerNormal() override;
    void printTest() const override;
    void printNormal() const override;
    ~MultipleChoiceQuestion() override = default;

    void saveToFile(std::ofstream& ofs) const override;
    void saveToBinaryFile(std::ofstream& ofs) const override;
    void readFromBinaryFile(std::ifstream& ifs) override;
};