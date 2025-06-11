#pragma once
#include "Question.h"
class SingleChoiceQuestion :
    public Question
{
private:
    MyString answer1, answer2, answer3, answer4;
    char rightAnswer;
public:
    SingleChoiceQuestion(const MyString& description, int points, const MyString& a1, const MyString& a2, const MyString& a3, const MyString& a4, char right);
   
    Question* clone() const override;
    void answerTest() override;
    bool answerNormal() override;
    void printTest() const override;
    void printNormal() const override;
    ~SingleChoiceQuestion() override = default;

    void saveToFile(std::ofstream& ofs) const override;
    void saveToBinaryFile(std::ofstream& ofs) const override;
    void readFromBinaryFile(std::ifstream& ifs) override;
};

