#include "../Header/DayFour.h"

DayFour::DayFour(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayFour::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::vector<int> row;

		for (size_t j = 0; j < ParsedFile[i].size(); j++)
		{
			row.push_back(ParsedFile[i][j] == '@' ? 1 : 0);
		}

		Grid.push_back(row);
	}
}

void DayFour::RunAssignment()
{
	int rollsAccessable = 0;

	for (size_t y = 0; y < Grid.size(); y++)
	{
		for (size_t x = 0; x < Grid[y].size(); x++)
		{
			if (Grid[y][x] != 0 && CanGridCoorBeAccessed(x, y, Grid))
			{
				rollsAccessable++;
			}
		}
	}

	std::cout << "There are " << rollsAccessable << " roles accessable" << std::endl;
}

void DayFour::RunBonusAssignment()
{
	int rollsAccessable = 0;
	int totalRollsAccessable = 0;
	std::vector<std::pair<int, int>> coorsToBeRemoved;
	bool nothingToRemove = true;

	while (nothingToRemove)
	{
		rollsAccessable = 0;

		for (size_t y = 0; y < Grid.size(); y++)
		{
			for (size_t x = 0; x < Grid[y].size(); x++)
			{
				if (Grid[y][x] != 0 && CanGridCoorBeAccessed(x, y, Grid))
				{
					rollsAccessable++;
					coorsToBeRemoved.push_back({ y,x });
				}
			}
		}

		if (rollsAccessable == 0)
		{
			nothingToRemove = false;
		}

		totalRollsAccessable += rollsAccessable;

		for (size_t i = 0; i < coorsToBeRemoved.size(); i++)
		{
			Grid[coorsToBeRemoved[i].first][coorsToBeRemoved[i].second] = 0;
		}
	}

	std::cout << "There are " << totalRollsAccessable << " roles accessable" << std::endl;
}

bool DayFour::CanGridCoorBeAccessed(int x, int y, std::vector<std::vector<int>>& grid)
{
	int minGridXCoor = (x == 0) ? x : x - 1;
	int minGridYCoor = (y == 0) ? y : y - 1;
	int maxGridXCoor = (x == grid[0].size() - 1) ? x : x + 1;
	int maxGridYCoor = (y == grid.size() - 1) ? y : y + 1;

	int paperCount = 0;

	for (size_t i = minGridYCoor; i <= maxGridYCoor; i++)
	{
		for (size_t j = minGridXCoor; j <= maxGridXCoor; j++)
		{
			if ((i == y && j == x))
			{
				continue;
			}

			if (Grid[i][j] == 1)
			{
				paperCount++;

				if (paperCount > 3)
				{
					return false;
				}
			}
		}
	}

	return true;
}