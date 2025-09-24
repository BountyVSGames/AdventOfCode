#pragma once
#include "Assignment.h"

class DayTwo : public Assignment
{
public:
    DayTwo(std::vector<std::string> parsedFile);

    void RunAssignment();
    void RunBonusAssignment();
private:
    bool RunRuleSet(std::vector<int> report);
    bool ContainsSingleBadLevel(int iterator, std::vector<int> report);

    int SaveReports;
    std::vector<std::vector<int>> Reports;
};