#pragma once
#include "Question.h"
class SingleChoiceQuestion :
    public Question
{
private:
    // 4 answers -> 1 right
    unsigned indexOfRightAnswer;
};

