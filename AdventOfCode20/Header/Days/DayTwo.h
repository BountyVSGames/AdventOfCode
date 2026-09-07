#pragma once
#include "../Assignment.h"

class DayTwo : public Assignment
{
	struct PasswordCheck
	{
		size_t minCharLenght = 0;
		size_t maxCharLenght = 0;
		char charRequirement = 0;
		std::string password;
	};


public:
	DayTwo(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Two"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	bool IsPasswordValidFirstPolicy(PasswordCheck passwordCheck);
	bool IsPasswordValidSecondPolicy(PasswordCheck passwordCheck);
	bool IsCharInRange(char c, int minCharIndx, int maxCharIndx);

	std::vector<PasswordCheck> passwordChecks;
};

