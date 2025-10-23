#include "DayNine.h"

DayNine::DayNine(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
	IndividualFreeSectorCount = 0;
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

				IndividualFreeSectorCount += 1;
			}		

			if (value != 0)
			{				
				SectoredDiskMap.push_back(sector);
				IdsFreeSectors.push_back({ SectoredDiskMap.size() - 1, sector.size() });
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
	long long index = 0;

	for (size_t i = 0; i < SectoredDiskMap.size(); i++)
	{
		for (size_t j = 0; j < SectoredDiskMap[i].size(); j++)
		{
			if (SectoredDiskMap[i][j] != -1)
			{
				result += (index * SectoredDiskMap[i][j]);		
			}

			index += 1;
		}
	}

	std::cout << "Resulting filesystem checksum: " << result << std::endl;
}

void DayNine::MoveFile()
{
	int indexToSwap = GetFirstIndexOfValue(DiskMap, -1);

	for (int i = ((int)DiskMap.size() - 1); i >= 0; i--)
	{
		if (IndividualFreeSectorCount == 0)
		{
			break;
		}

		if (DiskMap[i] == -1)
		{
			IndividualFreeSectorCount -= 1;
			continue;
		}

		for (size_t j = indexToSwap; j < DiskMap.size(); j++)
		{			
			if (DiskMap[j] != -1 && DiskMap[i] != -1)
			{
				DiskMap[indexToSwap] = DiskMap[i];
				DiskMap[i] = -1;
				
				indexToSwap = GetFirstIndexOfValue(DiskMap, -1);

				IndividualFreeSectorCount -= 1;
				break;
			}
		}
	}
}
void DayNine::MoveFileBlocks()
{
	int freeZoneCounter = 1;

	for (int i = ((int)SectoredDiskMap.size() - 1); i > 0; i--)
	{
		if (SectoredDiskMap[i][0] != -1)
		{
			for (size_t j = 0; j < IdsFreeSectors.size(); j++)
			{
				if (IdsFreeSectors[j].first > i)
				{
					break;
				}

				if(SectoredDiskMap[i].size() < IdsFreeSectors[j].second)
				{
					IdsFreeSectors[j].second -= SectoredDiskMap[i].size();

					SectoredDiskMap[IdsFreeSectors[j].first].resize(IdsFreeSectors[j].second);
					SectoredDiskMap.insert(SectoredDiskMap.begin() + IdsFreeSectors[j].first, SectoredDiskMap[i]);

					i += 1;

					for (size_t k = j; k < IdsFreeSectors.size(); k++)
					{
						IdsFreeSectors[k].first += 1;
					}
					for (size_t k = 0; k < SectoredDiskMap[i].size(); k++)
					{
						SectoredDiskMap[i][k] = -1;
					}

					break;
				}
				else if (IdsFreeSectors[j].second == SectoredDiskMap[i].size())
				{
					for (size_t k = 0; k < SectoredDiskMap[i].size(); k++)
					{
						SectoredDiskMap[IdsFreeSectors[j].first][k] = SectoredDiskMap[i][k];
						SectoredDiskMap[i][k] = -1;
					}

					IdsFreeSectors.erase(IdsFreeSectors.begin() + j);
					break;
				}
			}
		}
	}	
}

int DayNine::GetFirstIndexOfValue(std::vector<int> list, int value)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == value)
		{
			return i;
		}
	}

	return -1;
}