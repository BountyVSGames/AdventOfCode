#pragma once
#include "../Assignment.h"
class DaySeven : public Assignment
{
public:
	DaySeven(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Seven"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	bool IsEquationPossible(long long expectedResultEquation, std::vector<size_t> numbersEquation);
	bool IsEquationPossible(long long expectedResultEquation, std::vector<size_t> numbersEquation, std::vector<std::string> operators);

	std::vector<std::pair<long long, std::vector<size_t>>> Equations;
	std::vector<std::string> ParsedFile;
};

