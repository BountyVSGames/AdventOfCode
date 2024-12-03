#pragma once
#include "Assignment.h"

class DayTwo : public Assignment
{
public:
    DayTwo(std::vector<std::string> parsedFile);

    void RunAssignment();
    void RunBonusAssignment();
private: 
    int SaveReports;
    int UpdatedSaveReports;
    std::vector<std::string> UnsaveReports;
};