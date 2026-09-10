#pragma once
#include "../Assignment.h"
#include <map>

struct CustomsForm
{
	int personCount = 0;
	std::string answerStringFiltered = "";
	std::map<char, int> countPerChar;
};

class DaySix : public Assignment
{
public:
	DaySix(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Six"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<CustomsForm> customForms;
};