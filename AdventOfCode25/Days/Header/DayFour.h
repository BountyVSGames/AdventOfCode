#pragma once
#include "../..//Assignment.h"

class DayFour : public Assignment
{
public:
	DayFour(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Four"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<std::vector<int>> Grid;
	bool CanGridCoorBeAccessed(int x, int y, std::vector<std::vector<int>>& grid);
};

