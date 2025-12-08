#include "../Header/DaySeven.h"

DaySeven::DaySeven(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
	
}

void DaySeven::Initialize()
{

}

void DaySeven::RunAssignment()
{
	int beamSplits = 0;

	for (size_t x = 0; x < ParsedFile[0].size(); x++)
	{
		if (ParsedFile[0][x] == 'S')
		{
			MoveDownwards(x, 0, beamSplits);
			break;
		}
	}

	std::cout << "The tachyon beam is split a total of " << beamSplits << " times." << std::endl;
}

void DaySeven::RunBonusAssignment()
{

}

void DaySeven::MoveDownwards(size_t x, size_t y, int& it)
{
	if (y >= ParsedFile.size())
	{
		return;
	}

	char& cell = ParsedFile[y][x];

	if (cell == '|')
	{
		return;
	}

	if (cell != '^')
	{
		cell = '|';
		MoveDownwards(x,y + 1, it);
	}
	else
	{
		it++;

		if ((x + 1) < ParsedFile[y].size())
		{
			ParsedFile[y][x + 1] = '|';
			MoveDownwards(x + 1, y + 1, it);
		}

		if (x > 0)
		{
			ParsedFile[y][x - 1] = '|';
			MoveDownwards(x - 1, y + 1, it);
		}
	}	
}