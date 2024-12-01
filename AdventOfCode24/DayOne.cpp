#include "DayOne.h"

DayOne::DayOne(std::vector<std::string> parsedFile)
{
	TotalDistance = 0;
	SimulairityScore = 0;

	for (int i = 0; i < parsedFile.size(); i++)
	{
		int startSecondNumber = 0;
		int count = 0;

		for (char ch : parsedFile[i])
		{
			if (ch == ' ' && FirstNumbers.size() != (i + 1))
			{
				FirstNumbers.push_back(std::stoi(parsedFile[i].substr(0, count)));
			}
			else if (FirstNumbers.size() == (i + 1) && ch != ' ' && startSecondNumber == 0)
			{
				startSecondNumber = count;
			}

			count++;
		}

		SecondNumbers.push_back(std::stoi(parsedFile[i].substr(startSecondNumber, count)));
	}
}

void DayOne::RunAssignment()
{
	Sort(FirstNumbers);
	Sort(SecondNumbers);

	for (int i = 0; i < FirstNumbers.size(); i++)
	{
		Distance.push_back(FirstNumbers[i] - SecondNumbers[i]);
	}

	for (int i = 0; i < Distance.size(); i++)
	{
		TotalDistance += abs(Distance[i]);
	}

	std::cout << "Result first assignment: " << TotalDistance << std::endl;
}
void DayOne::RunBonusAssignment()
{
	for (int i = 0; i < SecondNumbers.size(); i++)
	{
		if (!SecondNumbersSimulairSorted.empty())
		{
			std::map<int, int>::iterator mapIndex = SecondNumbersSimulairSorted.find(SecondNumbers[i]);
			if (mapIndex != SecondNumbersSimulairSorted.end())
			{
				mapIndex->second += 1;
			}
		}

		SecondNumbersSimulairSorted.insert(std::pair<int, int>(SecondNumbers[i], 1));
	}

	for (int i = 0; i < FirstNumbers.size(); i++)
	{
		std::map<int, int>::iterator mapIndex = SecondNumbersSimulairSorted.find(FirstNumbers[i]);
		if (mapIndex != SecondNumbersSimulairSorted.end())
		{
			SimulairityScore += FirstNumbers[i] * mapIndex->second;
		}
	}
	
	std::cout << "Simulairity Score: " << SimulairityScore << std::endl;
}

void DayOne::Sort(std::vector<int>& numbersToSort)
{
	for (int i = 0; i < (numbersToSort.size() - 1); i++)
	{
		if (numbersToSort[i] > numbersToSort[i + 1])
		{
			int temp = numbersToSort[i];

			numbersToSort[i] = numbersToSort[i + 1];
			numbersToSort[i + 1] = temp;

			i = -1;
		}
	}
}