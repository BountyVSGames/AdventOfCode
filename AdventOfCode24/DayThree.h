#pragma once
#include "Assignment.h"

class DayThree : public Assignment
{
public:
	DayThree(std::vector<std::string> parsedFile);

	void RunAssignment();
	void RunBonusAssignment();

private:
	std::vector<std::string> ParsedFile;
	int result;
};