#include "DayTen.h"

DayTen::DayTen(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayTen::Initialize()
{
	for (size_t y = 0; y < ParsedFile.size(); y++)
	{
		for (size_t x = 0; x < ParsedFile[y].size(); x++)
		{
			if (ParsedFile[y][x] == '0')
			{
				TrailHeadCoor.push_back({ (int)y,(int)x });
				std::cout << ParsedFile[y][x];
				continue;
			}
			else if (ParsedFile[y][x] == '9')
			{
				EndTrailCoor.push_back({ (int)y, (int)x });
				std::cout << ParsedFile[y][x];
				continue;
			}
			
			std::cout << ".";
		}
		std::cout << std::endl;
	}
}

void DayTen::RunAssignment()
{
	int totalTrialsScore = 0;

	for (size_t i = 0; i < TrailHeadCoor.size(); i++)
	{
		totalTrialsScore += CalculatePossibleTrailFromHead(TrailHeadCoor[i]);
	}

	std::cout << "Sum of the scored of all trailheads is: " << totalTrialsScore << std::endl;
}

void DayTen::RunBonusAssignment()
{

}

int DayTen::CalculatePossibleTrailFromHead(std::pair<int, int> startTrailCoor)
{

}