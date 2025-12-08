#pragma once
#include "../../Assignment.h"

class DaySeven : public Assignment
{
public:
	DaySeven(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Seven"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	void MoveDownwards(size_t x, size_t y, int& it);
};

