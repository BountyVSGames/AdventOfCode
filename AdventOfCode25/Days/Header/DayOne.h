#pragma once
#include "../../Assignment.h"

class DayOne : public Assignment
{
public:
    DayOne(std::vector<std::string> parsedFile);

    std::string GetAssignmentName() { return "Day One"; };

    void Initialize();
    void RunAssignment();
    void RunBonusAssignment();
private:
    std::vector<int> SafeTurnDirectionValues;

    //Normal ruleset
    int CountsSafePointerAtZero = 0;
    //0x434C49434B ruleset
    int CountsSafePointerPassedZero = 0;

    void TurnSafe(int& safePointerLoc, int& safePointerDir);
};

