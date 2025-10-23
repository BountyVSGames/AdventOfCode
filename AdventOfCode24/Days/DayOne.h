#pragma once
#include "../Assignment.h"
#include <map>

class DayOne : public Assignment
{
public:
    DayOne(std::vector<std::string> parsedFile);

    std::string GetAssignmentName() { return "Day One"; };

    void Initialize();
    void RunAssignment();
    void RunBonusAssignment();

private:
    std::vector<int> FirstNumbers;
    std::vector<int> SecondNumbers;
    std::vector<int> Distance;

    std::map<int, int> SecondNumbersSimulairSorted;

    int TotalDistance;
    int SimulairityScore;

    void Sort(std::vector<int>& numbersToSort);
};

