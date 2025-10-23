#pragma once
#include <map>
#include "../Assignment.h"

class DayNine : public Assignment
{
public:
	DayNine(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Nine"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<int> DiskMap;

	int IndividualFreeSectorCount;

	std::vector<std::vector<int>> SectoredDiskMap;
	std::vector<std::pair<size_t, size_t>> IdsFreeSectors;

	void MoveFile();
	void MoveFileBlocks();
	int GetFirstIndexOfValue(std::vector<int> list, int value);
};

