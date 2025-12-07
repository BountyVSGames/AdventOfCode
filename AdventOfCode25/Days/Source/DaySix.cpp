#include "../Header/DaySix.h"

DaySix::DaySix(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DaySix::Initialize()
{
	size_t lastIndexParsedFile = ParsedFile.size() - 1;

	for (size_t i = 0; i < lastIndexParsedFile; i++)
	{
		int itNumber = 0;

		for (size_t j = 0; j < ParsedFile[i].size(); j++)
		{
			if (ParsedFile[i][j] == ' ')
			{
				continue;
			}

			size_t nextSpace = ParsedFile[i].find(' ', j);
			bool isLastNumber = nextSpace == std::string::npos;

			size_t lenghtOfString = (isLastNumber ? (ParsedFile[i].size() - j) : (nextSpace - j));
			size_t endIndex = (j + lenghtOfString);
			int numberToAdd = stoi(ParsedFile[i].substr(j, lenghtOfString));	

			if (itNumber >= allSums.size())
			{
				allSums.push_back(Sum({ numberToAdd }, j, endIndex));
			}
			else
			{
				allSums[itNumber].sum.push_back(numberToAdd);

				allSums[itNumber].lowestStartingIndex = (allSums[itNumber].lowestStartingIndex > j) ? j : allSums[itNumber].lowestStartingIndex;
				allSums[itNumber].highestEndingIndex = (allSums[itNumber].highestEndingIndex < endIndex) ? endIndex : allSums[itNumber].highestEndingIndex;
			}

			if (isLastNumber)
			{
				break;
			}

			itNumber++;
			j = nextSpace;
		}
	}

	size_t sizeOperatorsRow = ParsedFile[lastIndexParsedFile].size();

	for (size_t i = 0; i < sizeOperatorsRow; i++)
	{
		if (ParsedFile[lastIndexParsedFile][i] != ' ')
		{
			size_t nextSpace = ParsedFile[lastIndexParsedFile].find(' ', i);
			bool lastOperator = nextSpace == std::string::npos;
			std::string str = lastOperator ? ParsedFile[lastIndexParsedFile].substr(i, sizeOperatorsRow - i) :
												ParsedFile[lastIndexParsedFile].substr(i, nextSpace - i);
			
			Operators.push_back(str[0]);
		}
	}
}

void DaySix::RunAssignment()
{
	long long resultOfCombinedSums = 0;

	for (size_t i = 0; i < allSums.size(); i++)
	{
		resultOfCombinedSums += Calculate(allSums[i].sum, Operators[i]);
	}

	std::cout << "Grand total found by adding together all results: " << resultOfCombinedSums << std::endl;
}

void DaySix::RunBonusAssignment()
{
	long long resultOfCombinedSums = 0;

	for (size_t i = allSums.size(); i-- > 0;)
	{
		std::vector<int> newSum;
		
		for (size_t j = allSums[i].highestEndingIndex; j-- > allSums[i].lowestStartingIndex;)
		{
			std::string number;

			for (size_t row = 0; row < ParsedFile.size() - 1; row++)
			{
				if (ParsedFile[row][j] != ' ')
				{
					number.push_back(ParsedFile[row][j]);
				}
			}

			newSum.push_back(stoi(number));
		}

		resultOfCombinedSums += Calculate(newSum, Operators[i]);
	}

	std::cout << "Grand total found by adding together all results: " << resultOfCombinedSums << std::endl;
}

long long DaySix::Calculate(std::vector<int> sum, const char op)
{
	long long resultSum = sum[0];

	for (size_t j = 1; j < sum.size(); j++)
	{
		resultSum += ((op == '+') ? sum[j] : 0);
		resultSum *= ((op == '*') ? sum[j] : 1);
	}

	return resultSum;
}