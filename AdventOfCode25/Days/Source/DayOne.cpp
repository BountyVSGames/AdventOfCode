#include "../Header/DayOne.h"

DayOne::DayOne(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayOne::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		int value = std::stoi(ParsedFile[i].substr(1));
		const char dirChar = ParsedFile[i][0];

		if (dirChar == 'R')
		{
			SafeTurnDirectionValues.push_back(value);
			continue;
		}

		SafeTurnDirectionValues.push_back(-value);
	}
}

void DayOne::RunAssignment()
{
	int safePointerLoc = 50;
	int countsSafePointerAtZero = 0;

	for (size_t i = 0; i < SafeTurnDirectionValues.size(); i++)
	{
		TurnSafe(safePointerLoc, SafeTurnDirectionValues[i]);

		if (safePointerLoc == 0)
		{
			countsSafePointerAtZero++;
		}
	}

	std::cout << "The turner has rested on 0 a total of " << countsSafePointerAtZero << " times" << std::endl;
}

void DayOne::RunBonusAssignment()
{
	std::cout << "The turner has been on 0 a total of " << CountsSafePointerPassedZero << " times" << std::endl;
}

void DayOne::TurnSafe(int& safePointerLoc, int& safePointerDir)
{
	int dir = safePointerDir > 0 ? 1 : -1;
	int itCount = std::abs(safePointerDir);

	for (size_t i = 0; i < itCount; i++)
	{
		safePointerLoc += dir;

		if (safePointerLoc == 100)
		{
			safePointerLoc = 0;
		}
		else if (safePointerLoc == -1)
		{
			safePointerLoc = 99;
		}

		if (safePointerLoc == 0)
		{
			CountsSafePointerPassedZero++;
		}
	}
}