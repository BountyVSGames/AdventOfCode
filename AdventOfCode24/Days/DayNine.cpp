#include "DayNine.h"

DayNine::DayNine(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{

}

void DayNine::Initialize()
{
	int id = -1;

	for (size_t i = 0; i < ParsedFile[0].size(); i++)
	{
		int value = ParsedFile[0][i] - '0';
		std::vector<int> sector;
		
		if (i % 2 == 0)
		{	
			id += 1;

			for (size_t j = 0; j < value; j++)
			{
				DiskMap.push_back(id);
				sector.push_back(id);
			}

			if (value != 0)
			{
				SectoredDiskMap.push_back(sector);
			}
		}
		else
		{
			for (size_t j = 0; j < value; j++)
			{
				DiskMap.push_back(-1);
				sector.push_back(-1);

				FreeSectorCount += 1;
			}		

			if (value != 0)
			{				
				SectoredDiskMap.push_back(sector);
				IdsFreeSectors.push_back({ SectoredDiskMap.size(), sector.size() });
			}
		}
	}
}
void DayNine::RunAssignment()
{
	MoveFile();

	int64_t result = 0;

	for (size_t i = 0; i < DiskMap.size(); i++)
	{
		if (DiskMap[i] == -1)
		{
			break;
		}
		result += (i * DiskMap[i]);
	}

	std::cout << "Resulting filesystem checksum: " << result << std::endl;
}
void DayNine::RunBonusAssignment()
{
	MoveFileBlocks();

	int64_t result = 0;

	for (size_t i = 0; i < DiskMap.size(); i++)
	{
		if (DiskMap[i] == -1)
		{
			continue;
		}

		result += (i * DiskMap[i]);
	}

	std::cout << "Resulting filesystem checksum: " << result << std::endl;
}

void DayNine::MoveFile()
{
	int indexToSwap = GetFirstIndexOfValue(DiskMap, -1);

	for (int i = DiskMap.size() - 1; i >= 0; i--)
	{
		if (FreeSectorCount == 0)
		{
			break;
		}

		if (DiskMap[i] == -1)
		{
			FreeSectorCount -= 1;
			continue;
		}

		for (size_t j = indexToSwap; j < DiskMap.size(); j++)
		{			
			if (DiskMap[j] != -1 && DiskMap[i] != -1)
			{
				DiskMap[indexToSwap] = DiskMap[i];
				DiskMap[i] = -1;
				
				indexToSwap = GetFirstIndexOfValue(DiskMap, -1);

				FreeSectorCount -= 1;
				break;
			}
		}
	}
}
void DayNine::MoveFileBlocks()
{
	int freeZoneCounter = 1;

	for (int i = SectoredDiskMap.size() - 1; i > 0; i--)
	{
		if (SectoredDiskMap[i][0] != -1)
		{
			
		}

		//std::cout << SectoredDiskMap[i][0] << std::endl;
	}
}

int DayNine::GetFirstIndexOfValue(std::vector<int> list, int value)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == value)
		{
			return i;
		}
	}
}