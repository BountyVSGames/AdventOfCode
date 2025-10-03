#include "DaySix.h"

DaySix::DaySix(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{

}

void DaySix::Initialize()
{
	
}

void DaySix::RunAssignment()
{
	std::pair<int, int> guardLoc = FindCharacterLoc("^");
	GuardDirection dir = GuardDirection::up;
	std::pair<int, int> guardDir;
	size_t distinctPos = 0;

	bool outOfBounce = false;

	while (!outOfBounce)
	{
		if (ParsedFile[guardLoc.first][guardLoc.second] != 'X')
		{
			ParsedFile[guardLoc.first][guardLoc.second] = 'X';
			distinctPos++;
		}

		switch (dir)
		{
			case GuardDirection::up:
				guardDir = std::make_pair(-1, 0);
				break;
			case GuardDirection::right:
				guardDir = std::make_pair(0, 1);
				break;
			case GuardDirection::down:
				guardDir = std::make_pair(1, 0);
				break;
			case GuardDirection::left:
				guardDir = std::make_pair(0, -1);
		}

		std::pair<int, int> nextCoord = std::make_pair(guardLoc.first + guardDir.first, guardLoc.second + guardDir.second);

		if (((nextCoord.first) >= ParsedFile.size() ||
			(nextCoord.first) < 0) ||
			((nextCoord.second) >= ParsedFile[guardLoc.first].size() ||
				(nextCoord.second) < 0))
		{
			outOfBounce = true;
			break;
		}

		if (ParsedFile[nextCoord.first][nextCoord.second] == '#')
		{
			dir = static_cast<GuardDirection>((dir + 1) % 4);
			continue;
		}

		guardLoc.first = nextCoord.first;
		guardLoc.second = nextCoord.second;
	}

	std::cout << "The guard visited " << distinctPos << " distinct positions on the map." << std::endl;
}
void DaySix::RunBonusAssignment()
{

}

std::pair<int, int> DaySix::FindCharacterLoc(const char* character)
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		for (size_t j = 0; j < ParsedFile[i].size(); j++)
		{
			if (ParsedFile[i][j] == *character)
			{
				return std::make_pair(i, j);
			}
		}
	}
}