#pragma once
#include <map>
#include "Assignment.h"

class DayFive : public Assignment
{
public:
	DayFive(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Five"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	void OrderPageNumbers(std::vector<int>& numbers);

	bool CheckRuleSet(std::vector<int> numbers);

	std::vector<std::string> ParsedFile;
	std::vector<std::pair<size_t, size_t>> RuleSet;
	std::vector<std::vector<int>> OrderedPageNumbers;
	std::vector<std::vector<int>> NotOrderedPageNumbers;
};

