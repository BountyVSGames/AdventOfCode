#pragma once
#include <map>
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
	std::map<long long, long long> Stones;

	void Blink(int blinks);

	void AddValueToMap(std::map<long long, long long>& map, long long key, long long value);

	std::vector<long long> DisectInt(long long target);
	long long CombineInt(long long a, long long b);
};

