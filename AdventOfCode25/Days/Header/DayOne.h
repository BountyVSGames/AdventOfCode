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
};

