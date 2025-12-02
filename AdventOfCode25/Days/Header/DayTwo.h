#pragma once
#include "../../Assignment.h"

class DayTwo : public Assignment
{
public:
    DayTwo(std::vector<std::string> parsedFile);

    std::string GetAssignmentName() { return "Day Two"; };

    void Initialize();
    void RunAssignment();
    void RunBonusAssignment();
private:
    std::vector<std::pair<long long, long long>> AllIdRanges;
    std::vector<long long> ValidID;

    bool IsIDValid(long long id);
};