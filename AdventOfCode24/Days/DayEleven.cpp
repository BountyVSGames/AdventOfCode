#include "DayEleven.h"
#include <sstream>

DayEleven::DayEleven(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{

}

void DayEleven::Initialize()
{
	std::stringstream ss;
	ss << ParsedFile[0];

	while (!ss.eof())
	{
		long long found = 0;
		std::string temp = "";

		ss >> temp;

		if (std::stringstream(temp) >> found)
		{
			std::map<long long, long long>::iterator it = Stones.find(found);

			if (it != Stones.end())
			{
				Stones[it->first] += 1;
			}
			else
			{
				Stones.insert({ found, 1 });
			}
		}
	}
}

void DayEleven::RunAssignment()
{
	Blink(25);

	long long result = 0;

	for (std::map<long long, long long>::iterator it = Stones.begin(); it != Stones.end();)
	{
		result += it->second;

		it++;
	}

	std::cout << "There are " << result << " stones" << std::endl;
}

void DayEleven::RunBonusAssignment()
{
	Blink(50);

	long long result = 0;
	int iterator = 0;

	for (std::map<long long, long long>::iterator it = Stones.begin(); it != Stones.end();)
	{
		result += it->second;
		it++;
	}

	std::cout << "There are " << result << " stones" << std::endl;
}

void DayEleven::Blink(int blinks)
{
	for (size_t i = 0; i < blinks; i++)
	{
		std::map<long long, long long> newStoneMap;

		for (std::map<long long, long long>::iterator it = Stones.begin(); it != Stones.end();)
		{
			auto updateValue = Stones.extract(it++);

			if (updateValue.key() == 0)
			{
				AddValueToMap(newStoneMap, 1, updateValue.mapped());
			}
			else
			{
				std::vector<long long> stoneValueSeperated = DisectInt(updateValue.key());

				if (stoneValueSeperated.size() % 2)
				{
					updateValue.key() *= 2024;

					AddValueToMap(newStoneMap, updateValue.key(), updateValue.mapped());
				}
				else
				{
					size_t halfWayIndex = stoneValueSeperated.size() / 2;

					long long left = stoneValueSeperated[0];
					for (size_t k = 1; k < halfWayIndex; k++)
					{
						left = CombineInt(left, stoneValueSeperated[k]);
					}

					AddValueToMap(newStoneMap, left, updateValue.mapped());

					long long right = stoneValueSeperated[halfWayIndex];
					for (size_t k = halfWayIndex + 1; k < stoneValueSeperated.size(); k++)
					{
						right = CombineInt(right, stoneValueSeperated[k]);
					}

					AddValueToMap(newStoneMap, right, updateValue.mapped());
				}
			}
		}

		Stones = newStoneMap;
	}
}

void DayEleven::AddValueToMap(std::map<long long, long long>& map, long long key, long long value)
{
	std::pair<std::map<long long, long long>::iterator, bool> result = map.try_emplace(key, value);

	if (!result.second)
	{
		result.first->second += value;
	}
}

std::vector<long long> DayEleven::DisectInt(long long target)
{
	std::vector<long long> value;

	while (target > 0)
	{
		long long digit = target % 10;
		target /= 10;

		value.push_back(digit);
	}

	if (value.size() == 1)
	{
		return value;
	}

	int valueSize = (int)value.size();
	int maxIndexOfValue = (valueSize - 1);

	for (int i = maxIndexOfValue; i >= (valueSize / 2); i--)
	{
		int indexToSwap = maxIndexOfValue - i;
		long long temp = value[indexToSwap];

		value[indexToSwap] = value[i];
		value[i] = temp;
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