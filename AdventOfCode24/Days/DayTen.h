#pragma once
#include "../Assignment.h"

class DayTen : public Assignment
{
public:
	DayTen(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Ten"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
};

