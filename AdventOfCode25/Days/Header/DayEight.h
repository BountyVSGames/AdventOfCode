#pragma once
#include "../../Assignment.h"

struct Circuit;

struct Vec3
{
	int coor[3];
	Circuit* circuit;

	bool operator==(const Vec3& other) const
	{
		if (coor[0] == other.coor[0] &&
			coor[1] == other.coor[1] &&
			coor[2] == other.coor[2])
		{
			return true;
		}

		return false;
	}
};

struct Circuit
{
	std::vector<Vec3> JunctionBoxes;
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
	std::vector<Vec3> AllPos;

	double GetClosestBox(const Vec3& target, Vec3& closestBox);
	double Distance(const Vec3& a, const Vec3& b);
};

