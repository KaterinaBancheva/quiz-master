#pragma once
#include "Question.h"

class TrueOrFalseQuestion :
    public Question
{
private:
    bool correctAnswer;
public:
    TrueOrFalseQuestion();
    TrueOrFalseQuestion(const MyString& description, int points, bool correctAnswer);

    Question* clone() const override;
    void answerTest() override;
    bool answerNormal() override;
    void printTest() const override;
    void printNormal() const override;
    ~TrueOrFalseQuestion() override = default;

    void saveToFile(std::ofstream& ofs) const override;
    void saveToBinaryFile(std::ofstream& ofs) const override;
    void readFromBinaryFile(std::ifstream& ifs) override;
};

