#include "../../Header/Days/DayThree.h"

DayThree::DayThree(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayThree::Initialize()
{
	slopeSteps.push_back(std::pair<int, int>(3, 1));
	slopeSteps.push_back(std::pair<int, int>(1, 1));
	slopeSteps.push_back(std::pair<int, int>(5, 1));
	slopeSteps.push_back(std::pair<int, int>(7, 1));
	slopeSteps.push_back(std::pair<int, int>(1, 2));
}

void DayThree::RunAssignment()
{
	int treeFound = 0;
	std::pair<int, int> startingCoor = std::pair<int, int>(0, 0);

	Navigate(startingCoor, slopeSteps[0], treeFound);

	std::cout << "Trees encountered is " << treeFound << std::endl;
}

void DayThree::RunBonusAssignment()
{
	long long multipliedTreesFound = 0;
	std::pair<int, int> startingCoor = std::pair<int, int>(0, 0);
	
	for (size_t i = 0; i < slopeSteps.size(); i++)
	{
		int treeFound = 0;
		
		Navigate(startingCoor, slopeSteps[i], treeFound);

		if (multipliedTreesFound == 0)
		{
			multipliedTreesFound = treeFound;
		}
		else
		{
			multipliedTreesFound *= treeFound;
		}
	}

	std::cout << "Trees encountered on all paths multiplied is " << multipliedTreesFound << std::endl;
}

void DayThree::Navigate(std::pair<int, int> coor, std::pair<int, int> stepCoor, int& treeFound)
{
	if (coor.second >= ParsedFile.size())
	{
		return;
	}

	if (ParsedFile[coor.second][coor.first] == '#')
	{
		treeFound++;
	}

	std::pair<int, int> newCoor = std::pair<int, int>(((coor.first + stepCoor.first) % ParsedFile[0].size()),
		(coor.second + stepCoor.second));

	return Navigate(newCoor, stepCoor, treeFound);
}