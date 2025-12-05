#include "../Header/DayFive.h"

DayFive::DayFive(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayFive::Initialize()
{
	int it = 0;
	
	while (ParsedFile[it].size() > 0)
	{
		size_t splitIndex = ParsedFile[it].find('-');
		size_t secondNumberStartingIndex = splitIndex + 1;

		long long firstIndex = std::stoll(ParsedFile[it].substr(0, splitIndex));
		long long secondIndex = std::stoll(ParsedFile[it].substr(secondNumberStartingIndex, ParsedFile[it].size() - splitIndex));

		AllIDRanges.push_back({ firstIndex, secondIndex });

		it++;
	}

	MergeIDRanges();

	it++;

	for (size_t i = it; i < ParsedFile.size(); i++)
	{
		AvailableIngrediantID.push_back(std::stoll(ParsedFile[i]));
	}
}

void DayFive::RunAssignment()
{
	int freshIds = 0;

	for (size_t i = 0; i < AvailableIngrediantID.size(); i++)
	{
		if(IsIDInRange(AvailableIngrediantID[i]))
		{
			freshIds++;
		}
	}

	std::cout << freshIds << " of the available ingredient IDs are fresh." << std::endl;
}

void DayFive::RunBonusAssignment()
{
	long long allValidID = 0;

	for (size_t i = 0; i < AllIDRanges.size(); i++)
	{
		allValidID += AllIDRanges[i].second + 1 - AllIDRanges[i].first;
	}

	std::cout << "A total of " << allValidID << " are fresh" << std::endl;
}

bool DayFive::IsIDInRange(long long id)
{
	for (size_t i = 0; i < AllIDRanges.size(); i++)
	{
		if (id >= AllIDRanges[i].first && id <= AllIDRanges[i].second)
		{
			return true;
		}
	}

	return false;
}

void DayFive::MergeIDRanges()
{
	for (int i = (int)AllIDRanges.size() - 1; i >= 0; i--)
	{
		for (size_t j = 0; j < AllIDRanges.size(); j++)
		{
			if (i == j)
			{
				continue;
			}

			long long firstIndex = 0;
			long long secondIndex = 0;

			if (AllIDRanges[i].first >= AllIDRanges[j].first && AllIDRanges[i].first <= AllIDRanges[j].second)
			{
				firstIndex = AllIDRanges[j].first;

				if (AllIDRanges[i].second >= AllIDRanges[j].second)
				{
					secondIndex = AllIDRanges[i].second;
				}
			}

			if (AllIDRanges[i].second <= AllIDRanges[j].second && AllIDRanges[i].second >= AllIDRanges[j].first)
			{
				secondIndex = AllIDRanges[j].second;

				if (AllIDRanges[i].first <= AllIDRanges[j].first)
				{
					firstIndex = AllIDRanges[i].first;
				}
			}

			if (firstIndex != 0 || secondIndex != 0)
			{
				if (firstIndex != 0)
				{
					AllIDRanges[j].first = firstIndex;
				}

				if (secondIndex != 0)
				{
					AllIDRanges[j].second = secondIndex;
				}

				AllIDRanges.erase(AllIDRanges.begin() + i);
				break;
			}
		}
	}
}