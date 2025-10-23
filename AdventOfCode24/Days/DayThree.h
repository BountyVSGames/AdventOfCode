#pragma once
#include <map>
#include "../Assignment.h"

class DayThree : public Assignment
{
public:
	DayThree(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Three"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	void RunConditionalChecks();
	int CalculateResult();

	std::string Input;

	std::map<size_t, size_t> MulIntructions;
	std::map<size_t, size_t> ConditionalInstructions;
};