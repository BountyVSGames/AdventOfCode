#pragma once
#include "../Assignment.h"
class DayFour : public Assignment
{
public:
	DayFour(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Four"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<std::string> ParsedFile;
	std::vector<std::pair<int, int>> XCoordinates;
	std::vector<std::pair<int, int>> ACoordinates;
};

