#pragma once
#include "Assignment.h"
class DayFour : public Assignment
{
public:
	DayFour(std::vector<std::string> parsedFile);

	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<std::string> ParsedFile;
};

