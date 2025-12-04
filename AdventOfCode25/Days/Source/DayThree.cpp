#include "../Header/DayThree.h"

DayThree::DayThree(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayThree::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::vector<int> bank;

		for (size_t j = 0; j < ParsedFile[i].size(); j++)
		{
			bank.push_back(ParsedFile[i][j] - '0');
		}

		AllBanks.push_back(bank);
	}
}

void DayThree::RunAssignment()
{
	int totalOutputJoltage = 0;

	for (size_t i = 0; i < AllBanks.size(); i++)
	{
		totalOutputJoltage += GetJoltageFromBank(AllBanks[i]);
	}

	std::cout << "Total output joltage of all banks: " << totalOutputJoltage << std::endl;
}

void DayThree::RunBonusAssignment()
{

}

int DayThree::GetJoltageFromBank(const std::vector<int>& bank)
{
	int firstNumber = 0;
	int secondNumber = 0;

	int firstNumberIt = 0;

	for (size_t i = 0; i < bank.size() - 1; i++)
	{
		if (bank[i] > firstNumber)
		{
			firstNumber = bank[i];
			firstNumberIt = i + 1;
		}
	}

	for (size_t j = firstNumberIt; j < bank.size(); j++)
	{
		if (bank[j] > secondNumber)
		{
			secondNumber = bank[j];
		}
	}

	return (firstNumber * 10) + secondNumber;
}