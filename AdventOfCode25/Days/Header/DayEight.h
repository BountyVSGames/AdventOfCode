#pragma once
#include "../../Assignment.h"

struct Circuit;

struct JunctionBox
{
	double coor[3];
};

struct Circuit
{
	Circuit(size_t a, size_t b)
	{
		startBoxA = a;
		startBoxB = b;

		junBox.push_back(a);
		junBox.push_back(b);
	}

	size_t startBoxA;
	size_t startBoxB;

	std::vector<size_t> junBox;
};

struct JunctionPair
{
	JunctionPair(size_t a, size_t b, double dist) : indxBoxA(a), indxBoxB(b)
	{
		distance = dist;
	}

	size_t indxBoxA;
	size_t indxBoxB;

	double distance;
};

class DayEight : public Assignment
{
public:
	DayEight(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Eight"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

private:
	std::vector<JunctionBox> AllPos;
	std::vector<JunctionPair> AllPairs;
	std::vector<Circuit> AllCircuits;

	double Distance(const JunctionBox& a, const JunctionBox& b);
	void QuickSortJunctionPair(std::vector<JunctionPair>& pairsToSort, int left, int right);
	void QuickSortCircuits(std::vector<Circuit>& pairsToSort, int left, int right);
};

