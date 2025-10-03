#pragma once
#include "Assignment.h"
class DaySix : public Assignment
{
	enum GuardDirection
	{
		up = 0, 
		right = 1, 
		down = 2, 
		left = 3
	};

public:
	DaySix(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Six"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	std::vector<std::string> ParsedFile;
	std::pair<int, int> FindCharacterLoc(const char* character);
};

