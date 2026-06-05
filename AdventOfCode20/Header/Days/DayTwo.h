#pragma once
#include "../Assignment.h"

class DayTwo : public Assignment
{
	struct PasswordCheck
	{
		int minCharLenght;
		int maxCharLenght;
		char charRequirement;
		std::string password;
	};


public:
	DayTwo(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day One"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	bool IsCharInRange(char c, int minCharIndx, int maxCharIndx);

	//std::string 
};

