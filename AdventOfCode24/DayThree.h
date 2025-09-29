#pragma once
#include <map>
#include "Assignment.h"

class DayThree : public Assignment
{
public:
	DayThree(std::vector<std::string> parsedFile);

	void RunAssignment();
	void RunBonusAssignment();

private:
	void RunConditionalChecks();
	int CalculateResult();

	std::vector<std::string> ParsedFile;
	std::string Input;

	std::map<size_t, size_t> MulIntructions;
	std::map<size_t, size_t> ConditionalInstructions;
};