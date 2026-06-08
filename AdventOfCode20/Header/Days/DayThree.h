#pragma once
#include "../../Header/Assignment.h"

class DayThree : public Assignment
{
public:
	DayThree(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Three"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	void Navigate(std::pair<int, int> coor, std::pair<int, int> stepCoor, int& treeFound);

	std::vector<std::pair<int, int>> slopeSteps;
};

