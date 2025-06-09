//#pragma once
//#include "Question.h"
//#include "MyVector.hpp"
//#include "Pair.h"
//
//class MatchingPairsQuestion :
//    public Question
//{
//private:
//    unsigned int leftColumnCount, rightColumnCount;
//    MyVector<Pair> answers;
//public:
//    MatchingPairsQuestion(const MyString& description, int points, unsigned int leftColumnCount, unsigned int rightColumnCount);
//
//    Question* clone() const override;
//    void answer() override;
//    void printTest() const override;
//    void printNormal() const override;
//    ~MatchingPairsQuestion() override = default;
//
//    void saveToFile(std::ofstream& ofs) const override;
//    void saveToBunaryFile(std::ostream& os) const override;
//    void readFromBinaryFile(std::istream& is) override;
//};