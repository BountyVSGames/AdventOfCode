#include "DayFive.h"
#include <sstream>

DayFive::DayFive(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
	
}

void DayFive::Initialize()
{
	std::vector<std::vector<size_t>> pageNumbers;
	int iterator = 0;

	while (ParsedFile[iterator].size() != 0)
	{
		size_t pos = ParsedFile[iterator].find('|');
		int LeftNumber = std::stoi(ParsedFile[iterator].substr(0, pos));
		int RightNumber = std::stoi(ParsedFile[iterator].substr(pos + 1, ParsedFile[iterator].size()));
	
		RuleSet.push_back({ LeftNumber, RightNumber });
		iterator++;
	}

	iterator++;

	while (iterator < ParsedFile.size())
	{
		std::vector<size_t> numbers;
		numbers.push_back(std::stoi(ParsedFile[iterator].substr(0, 2)));

		size_t pos = ParsedFile[iterator].find(',');

		while (pos != std::string::npos)
		{
			numbers.push_back(std::stoi(ParsedFile[iterator].substr(pos + 1, pos + 2)));
			pos = ParsedFile[iterator].find(',', pos + 1);
		}

		pageNumbers.push_back(numbers);
		iterator++;
	}

	std::vector<std::pair<size_t, size_t>>::iterator it;
	for (size_t i = 0; i < pageNumbers.size(); i++)
	{
		if (CheckRuleSet(pageNumbers[i]))
		{
			OrderedPageNumbers.push_back(pageNumbers[i]);
		}
		else
		{
			NotOrderedPageNumbers.push_back(pageNumbers[i]);
		}
	}
}
void DayFive::RunAssignment()
{
	size_t result = 0;

	for (size_t i = 0; i < OrderedPageNumbers.size(); i++)
	{
		result += OrderedPageNumbers[i][OrderedPageNumbers[i].size() / 2];
	}

	std::cout << "Result: " << result << std::endl;
}
void DayFive::RunBonusAssignment()
{
	size_t result = 0;

	for (size_t i = 0; i < NotOrderedPageNumbers.size(); i++)
	{
		OrderPageNumbers(NotOrderedPageNumbers[i]);

		result += NotOrderedPageNumbers[i][NotOrderedPageNumbers[i].size() / 2];
	}

	std::cout << "Result: " << result << std::endl;
}

void DayFive::OrderPageNumbers(std::vector<size_t>& numbers)
{
	std::vector<std::pair<size_t, size_t>>::iterator it;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::vector<size_t> rulesFound;

		for (it = RuleSet.begin(); it != RuleSet.end();)
		{
			if (numbers[i] == it->first)
			{
				rulesFound.push_back(it->second);
			}

			it++;
		}

		bool ruleFound = false;

		for (size_t j = 0; j < rulesFound.size(); j++)
		{
			for (size_t k = 0; k <= i; k++)
			{
				if (rulesFound[j] == numbers[k])
				{
					size_t temp = numbers[i];

					numbers[i] = numbers[k];
					numbers[k] = temp;

					i--;
				}
			}
		}
	}
}

bool DayFive::CheckRuleSet(std::vector<size_t> numbers)
{
	std::vector<std::pair<size_t, size_t>>::iterator it;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::vector<size_t> rulesFound;

		for (it = RuleSet.begin(); it != RuleSet.end();)
		{
			if (numbers[i] == it->first)
			{
				rulesFound.push_back(it->second);
			}

			it++;
		}

		for (size_t j = 0; j < rulesFound.size(); j++)
		{
			for (size_t k = 0; k <= i; k++)
			{
				if (rulesFound[j] == numbers[k])
				{
					return false;
				}
			}
		}
	}

	return true;
}