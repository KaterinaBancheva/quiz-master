#pragma once
#include "Question.h"
#include "MyVector.hpp"
#include "Pair.h"

class MatchingPairsQuestion :
    public Question
{
private:
    MyVector<MyString> leftColumn, rightColumn;
    MyVector<Pair> answers;
    int pointsToGet = points;

    Pair getPair(const char* str);
    bool contains(const Pair& p) const;
public:
    MatchingPairsQuestion();
    MatchingPairsQuestion(const MyString& description, int points, MyVector<MyString>& leftColumn, MyVector<MyString>& rightColumn, MyVector<Pair>& answers);
    int getQuestionPoints() const override;

    Question* clone() const override;
    void answerTest() override;
    bool answerNormal() override;
    void printTest() const override;
    void printNormal() const override;
    ~MatchingPairsQuestion() override = default;

    void saveToFile(std::ofstream& ofs) const override;
    void saveToBinaryFile(std::ofstream& ofs) const override;
    void readFromBinaryFile(std::ifstream& ifs) override;
};