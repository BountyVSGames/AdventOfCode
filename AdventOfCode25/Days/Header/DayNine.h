#pragma once
#include "../../Assignment.h"

struct Rectangle
{
	Rectangle() {};
	Rectangle(std::pair<int, int> firstPos, std::pair<int, int> secondPos, long long size)
	{
		FirstPos = firstPos;
		SecondPos = secondPos;
		Size = size;
	}

	std::pair<int, int> FirstPos;
	std::pair<int, int> SecondPos;

	bool operator==(const Rectangle& other)
	{
		return(other.FirstPos == FirstPos && other.SecondPos == SecondPos);
	}

	long long Size;
};

class DayNine : public Assignment
{

public:
	DayNine(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Nine"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();

	std::vector<std::pair<int, int>> AllCoors;
	std::vector<Rectangle> AllRectangles;

	bool CombinedExists(std::pair<int, int> first, std::pair<int, int> second);
	Rectangle CalculateRectangle(std::pair<int, int> first, std::pair<int, int> second);
};