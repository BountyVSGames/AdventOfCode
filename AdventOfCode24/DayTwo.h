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
    int OneErrorReports;
    std::vector<std::vector<int>> Reports;
    //std::vector<std::string> UnsaveReports;
};