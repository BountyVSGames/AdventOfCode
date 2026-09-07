#include "../../Header/Days/DayFive.h"

DayFive::DayFive(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayFive::Initialize()
{
	std::pair<char, char> rowCharRule = std::pair<char, char>('B', 'F');
	std::pair<char, char> columnCharRule = std::pair<char, char>('R', 'L');

	std::pair<int, int> rowRange;
	std::pair<int, int> columnRange;

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		int it = 0;

		rowRange = std::pair<int, int>(0, 127);
		columnRange = std::pair<int, int>(0, 7);

		int row = GetRow(rowCharRule, rowRange, ParsedFile[i], it);
		int column = GetRow(columnCharRule, columnRange, ParsedFile[i], it);

		int seatID = row * 8 + column;
		seatIDs.push_back(seatID);
	}

	BubbleSort(seatIDs);
}

void DayFive::RunAssignment()
{
	std::cout << "Higest seat ID is: " << seatIDs[seatIDs.size() - 1] << std::endl;;
}
void DayFive::RunBonusAssignment()
{
	std::cout << "My seat is ID: " << GetMissingSeat(seatIDs) << std::endl;
}

int DayFive::GetRow(std::pair<char, char>& charRule, std::pair<int, int>& range, std::string& chars, int& it)
{
	if (range.first == range.second)
	{
		return range.first;
	}

	int halfWayValue = (range.first + range.second) / 2;

	range.first = chars[it] == charRule.first ? halfWayValue + 1 : range.first;
	range.second = chars[it] == charRule.second ? halfWayValue : range.second;

	it += 1;

	return GetRow(charRule, range, chars, it);
}
int DayFive::GetMissingSeat(std::vector<int>& seatIDs)
{
	for (size_t i = 0; i < seatIDs.size(); i++)
	{
		if (seatIDs[i] != seatIDs[0] + i)
		{
			return seatIDs[0] + (int)i;
		}
	}

	return -1;
}

void DayFive::BubbleSort(std::vector<int>& vecToSort)
{
	for (size_t i = 0; i < vecToSort.size() - 1; i++)
	{
		for (size_t j = 0; j < vecToSort.size() - i - 1; j++)
		{
			if (vecToSort[j] > vecToSort[j + 1])
			{
				int tempValue = vecToSort[j];
				vecToSort[j] = vecToSort[j + 1];
				vecToSort[j + 1] = tempValue;
			}
		}
	}
}