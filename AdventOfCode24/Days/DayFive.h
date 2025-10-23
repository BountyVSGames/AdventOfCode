#pragma once
#include <map>
#include "../Assignment.h"

class DayFive : public Assignment
{
public:
	DayFive(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Five"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	void OrderPageNumbers(std::vector<size_t>& numbers);

	bool CheckRuleSet(std::vector<size_t> numbers);

	std::vector<std::pair<size_t, size_t>> RuleSet;
	std::vector<std::vector<size_t>> OrderedPageNumbers;
	std::vector<std::vector<size_t>> NotOrderedPageNumbers;
};

