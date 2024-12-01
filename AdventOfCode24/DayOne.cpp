#include "DayOne.h"

void DayOne::RunAssignment(std::vector<std::string> parsedFile)
{
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

	Sort(FirstNumbers);
	Sort(SecondNumbers);

	for (int i = 0; i < FirstNumbers.size(); i++)
	{
		Distance.push_back(FirstNumbers[i] - SecondNumbers[i]);

		std::cout << FirstNumbers[i] << " " << SecondNumbers[i] << " Result: " << abs(Distance[i]) << std::endl;
	}

	for (int i = 0; i < Distance.size(); i++)
	{
		Result += abs(Distance[i]);
	}

	std::cout << "Result first assignment: " << Result << std::endl;
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