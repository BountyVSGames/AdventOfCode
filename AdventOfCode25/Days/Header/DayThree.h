#pragma once
#include "../../Assignment.h"

class DayThree : public Assignment
{
public:
    DayThree(std::vector<std::string> parsedFile);

    std::string GetAssignmentName() { return "Day Three"; };

    void Initialize();
    void RunAssignment();
    void RunBonusAssignment();

private:
    std::vector<std::vector<int>> AllBanks;

    int GetJoltageFromBank(const std::vector<int>& bank);
};

