#pragma once
#include "Assignment.h"
class DaySeven : public Assignment
{
public:
	DaySeven(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Seven"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	bool IsEquationPossible(size_t expectedResultEquation, std::vector<size_t> numbersEquation);

	size_t result;

	std::vector<std::string> ParsedFile;
};

