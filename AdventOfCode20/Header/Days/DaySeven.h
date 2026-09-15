#pragma once
#include "../Assignment.h"
#include <map>

class DaySeven : public Assignment
{
public:
	DaySeven(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Seven"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::map<std::string, std::vector<std::string>> bagRules;

	void GetContainedBagFromRules(std::string bagName, std::string& bagsFound, int& count);
	void GetCountContainedInBag(std::string bagName, int& bagCounter);
};

