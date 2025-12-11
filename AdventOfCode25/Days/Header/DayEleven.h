#pragma once
#include <unordered_map>
#include <map>
#include "../../Assignment.h"

class DayEleven : public Assignment
{
public:
	DayEleven(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Eleven"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::unordered_map<int, std::vector<int>> AllConnectionPaths;

	int StartDeviceIndex = -1;
	int StartBonusDeviceIndex = -1;

	int IndexDac = -1;
	int IndexFft = -1;

	void GetAllPaths(int index, int& allPaths);
	void GetAllPaths(int index, int& allPaths, std::vector<int>& current);
};

