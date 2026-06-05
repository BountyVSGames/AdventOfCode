#include "../../Header/Days/DayOne.h"

DayOne::DayOne(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
};

void DayOne::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		for (size_t j = i; j < ParsedFile.size(); j++)
		{
			int firstValue = std::stoi(ParsedFile[i]);
			int secondValue = std::stoi(ParsedFile[j]);

			int together = firstValue + secondValue;

			if (together == targetValue)
			{
				firstAnswer = firstValue * secondValue;
			}

			for (size_t k = j; k < ParsedFile.size(); k++)
			{
				int thirdValue = std::stoi(ParsedFile[k]);

				if ((together + thirdValue) == targetValue)
				{
					secondAnswer = firstValue * secondValue * thirdValue;
				}
			}
		}
	}
}

void DayOne::RunAssignment()
{
	std::cout << "The product of the two entries that sum to 2020 is " << firstAnswer << std::endl;
}
void DayOne::RunBonusAssignment()
{
	std::cout << "The product of the three entries that sum to 2020 is " << secondAnswer << std::endl;
}