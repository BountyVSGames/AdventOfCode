#pragma once
#include "Assignment.h"
class DayOne : public Assignment
{
public:
    void RunAssignment(std::vector<std::string> parsedFile);
private:
    std::vector<int> FirstNumbers;
    std::vector<int> SecondNumbers;
    std::vector<int> Distance;

    int Result;

    void Sort(std::vector<int>& numbersToSort);
};

