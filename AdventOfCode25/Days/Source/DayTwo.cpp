#include "../Header/DayTwo.h"

DayTwo::DayTwo(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayTwo::Initialize()
{
	size_t idRangeSplitIndex = 0;

	while (idRangeSplitIndex != std::string::npos)
	{
		size_t splitIndex = ParsedFile[0].find('-', idRangeSplitIndex);
		size_t firstNumberStartingIndex = idRangeSplitIndex == 0 ? idRangeSplitIndex : idRangeSplitIndex + 1;
		size_t secondNumberStartingIndex = splitIndex + 1;

		idRangeSplitIndex = ParsedFile[0].find(',', idRangeSplitIndex + 1);

		long long firstIndex = std::stoll(ParsedFile[0].substr(firstNumberStartingIndex, splitIndex - firstNumberStartingIndex));
		long long secondIndex = std::stoll(ParsedFile[0].substr(secondNumberStartingIndex, idRangeSplitIndex - (secondNumberStartingIndex)));

		AllIdRanges.push_back({ firstIndex , secondIndex });
	}
}

void DayTwo::RunAssignment()
{
	long long allInvalidIDCount = 0;

	for (size_t i = 0; i < AllIdRanges.size(); i++)
	{
		for (long long j = AllIdRanges[i].first; j <= AllIdRanges[i].second; j++)
		{
			if (!IsIDValid(j))
			{
				allInvalidIDCount += j;
				continue;
			}

			ValidID.push_back(j);
		}
	}

	std::cout << "All the invalid ID's added up produced: " << allInvalidIDCount << std::endl;
}

void DayTwo::RunBonusAssignment()
{
	//Run through all valid ids to see if sequence repeats more then once

	for (size_t i = 0; i < ValidID.size(); i++)
	{
		std::cout << ValidID[i] << std::endl;
	}
}

bool DayTwo::IsIDValid(long long id)
{
	std::string value = std::to_string(id);
	bool doesValueHaveEvenLenght = (value.size() % 2) == 0;

	if (!doesValueHaveEvenLenght)
	{
		return true;
	}

	long halfwayIndex = (long)value.size() / 2;

	for (long long i = 0; i < halfwayIndex; i++)
	{
		if (value[i] != value[i + halfwayIndex])
		{
			return true;
		}
	}

	return false;
}