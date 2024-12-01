#pragma once
#include "Assignment.h"
class DayOne : public Assignment
{
public:
    DayOne(std::vector<std::string> parsedFile);

    void RunAssignment();
    void RunBonusAssignment();

private:
    std::vector<int> FirstNumbers;
    std::vector<int> SecondNumbers;
    std::vector<int> Distance;

    int Result;

    void Sort(std::vector<int>& numbersToSort);
};

