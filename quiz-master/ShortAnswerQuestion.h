#pragma once
#include "Question.h"

class ShortAnswerQuestion :
    public Question
{
private:
    MyString correctAnswer;

    void normalizeAnswer(MyString& str);
    std::string trim(const std::string& str);
public:
    ShortAnswerQuestion();
    ShortAnswerQuestion(const MyString& description, int points, const MyString& correctAnswer);

    Question* clone() const override;
    void answerTest() override;
    bool answerNormal() override;
    void printTest() const override;
    void printNormal() const override;
    ~ShortAnswerQuestion() override = default;

    void saveToFile(std::ofstream& ofs) const override;
    void saveToBinaryFile(std::ofstream& ofs) const override;
    void readFromBinaryFile(std::ifstream& ifs) override;
};