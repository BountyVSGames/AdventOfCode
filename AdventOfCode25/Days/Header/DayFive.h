#pragma once
#include "../../Assignment.h"
#include <set>

class DayFive : public Assignment
{
public:
	DayFive(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Five"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<std::pair<long long, long long>> AllIDRanges;
	std::vector<long long> AvailableIngrediantID;

	bool IsIDInRange(long long id);
	void MergeIDRanges();
};

