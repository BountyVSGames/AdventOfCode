#pragma once
#include "../../Assignment.h"

class DaySix : public Assignment
{
	struct Sum
	{
		Sum(std::vector<int> value, size_t startIndex, size_t endIndex) : sum(value)
		{
			lowestStartingIndex = startIndex;
			highestEndingIndex = endIndex;
		};

		std::vector<int> sum;
		size_t lowestStartingIndex;
		size_t highestEndingIndex;
	};

public:
	DaySix(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Six"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<Sum> allSums;
	std::vector<char> Operators;

	long long Calculate(std::vector<int> sum, const char op);
};

