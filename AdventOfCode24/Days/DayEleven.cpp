#include "DayEleven.h"
#include <sstream>

DayEleven::DayEleven(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{
	std::stringstream ss;
	ss << ParsedFile[0];	

	while (!ss.eof())
	{
		int found = 0;
		std::string temp = "";

		ss >> temp;

		if (std::stringstream(temp) >> found)
		{
			Stones.push_back(found);
		}
	}
}

void DayEleven::Initialize()
{
}

void DayEleven::RunAssignment()
{
	StonesAfterBlinking = Blink(Stones, 25);

	std::cout << "There are " << StonesAfterBlinking.size() << " stones" << std::endl;
}

void DayEleven::RunBonusAssignment()
{
	StonesAfterBlinking = Blink(StonesAfterBlinking, 50);

	std::cout << "There are " << StonesAfterBlinking.size() << " stones" << std::endl;
}

std::vector<long long> DayEleven::Blink(std::vector<long long> stones, int blinks, int it)
{
	if (it == blinks)
	{
		return stones;
	}

	std::vector<long long> newStoneArrangement;

	for (size_t i = 0; i < stones.size(); i++)
	{
		if (stones[i] == 0)
		{
			newStoneArrangement.push_back(1);
		}
		else
		{
			std::vector<long long> stoneValueSeperated = DisectInt(stones[i]);

			if (!(stoneValueSeperated.size() % 2))
			{
				size_t halfWayIndex = stoneValueSeperated.size() / 2;
				long long value = stoneValueSeperated[0];

				for (size_t i = 1; i < halfWayIndex; i++)
				{
					value = CombineInt(value, stoneValueSeperated[i]);
				}

				newStoneArrangement.push_back(value);

				value = stoneValueSeperated[halfWayIndex];

				for (size_t i = halfWayIndex + 1; i < stoneValueSeperated.size(); i++)
				{
					value = CombineInt(value, stoneValueSeperated[i]);
				}

				newStoneArrangement.push_back(value);
			}
			else
			{
				newStoneArrangement.push_back(stones[i] * 2024);
			}
		}
	}

	return Blink(newStoneArrangement, blinks, it + 1);
}

std::vector<long long> DayEleven::DisectInt(long long target)
{
	std::vector<long long> tempValue;
	std::vector<long long> value;

	while (target > 0)
	{
		long long digit = target % 10;
		target /= 10;

		tempValue.push_back(digit);
	}

	for (int i = (int)(tempValue.size() - 1); i >= 0; i--)
	{
		value.push_back(tempValue[i]);
	}

	return value;
}
long long DayEleven::CombineInt(long long a, long long b)
{
	int times = 10;

	while (b >= times)
	{
		times *= 10;
	}

	return (a * times) + b;
}