#pragma once
#include "../Assignment.h"

class DayEleven : public Assignment
{
public:	
	DayEleven(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Eleven"; }

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	std::vector<long long> Stones;
	std::vector<long long> StonesAfterBlinking;

	std::vector<std::string> ParsedFile;

	std::vector<long long> Blink(std::vector<long long> stones, int blinks, int it = 0);

	std::vector<long long> DisectInt(long long target);
	long long CombineInt(long long a, long long b);
};

