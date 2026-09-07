#pragma once
#include "../Assignment.h"

class DayFive : public Assignment
{
public:
	DayFive(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Five"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<int> seatIDs;

	int GetRow(std::pair<char, char>& charRule, std::pair<int, int>& range, std::string& chars);
	int GetMissingSeat(std::vector<int>& seatIDs);
	
	void BubbleSort(std::vector<int>& vecToSort);

};