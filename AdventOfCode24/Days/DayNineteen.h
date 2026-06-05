#pragma once
#include "../Assignment.h"

class DayNineteen : public Assignment
{
public:
	DayNineteen(std::vector<std::string> parsedFile);
	
	std::string GetAssignmentName() { return "Day Nineteen"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	std::vector<std::string> patterns;

	bool FindPatternInString(std::string& string, std::string& pattern, size_t& indexPatternOnString);
};

