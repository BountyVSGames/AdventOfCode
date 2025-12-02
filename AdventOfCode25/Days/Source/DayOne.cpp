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

		value = dirChar == 'R' ? value : -value;
		SafeTurnDirectionValues.push_back(value);
	}
}

void DayOne::RunAssignment()
{
	int safePointerLoc = 50;

	for (size_t i = 0; i < SafeTurnDirectionValues.size(); i++)
	{
		TurnSafe(safePointerLoc, SafeTurnDirectionValues[i]);

		if (safePointerLoc == 0)
		{
			CountsSafePointerAtZero++;
		}
	}

	std::cout << "The turner has rested on 0 a total of " << CountsSafePointerAtZero << " times" << std::endl;
}

void DayOne::RunBonusAssignment()
{
	std::cout << "The turner has been on 0 a total of " << CountsSafePointerPassedZero << " times" << std::endl;
}

void DayOne::TurnSafe(int& safePointerLoc, int& safePointerDir)
{
	int dir = safePointerDir > 0 ? 1 : -1;

	for (size_t i = 0; i < std::abs(safePointerDir); i++)
	{
		safePointerLoc += dir;

		if (safePointerLoc == 100 || safePointerLoc == -1)
		{
			safePointerLoc = safePointerLoc == 100 ? 0 : 99;
		}

		if (safePointerLoc == 0)
		{
			CountsSafePointerPassedZero++;
		}
	}
}