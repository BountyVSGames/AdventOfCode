#include "DaySeven.h"
#include <sstream>

DaySeven::DaySeven(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{

}

void DaySeven::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::pair<long long, std::vector<size_t>> equation;

		//Values could exceed int limit. Should be long long int
		size_t split = ParsedFile[i].find(':');
		equation.first = std::stoll(ParsedFile[i].substr(0, split));

		std::stringstream ss;
		std::string temp = "";
		int found = 0;

		ss << ParsedFile[i].substr(split + 2);
		
		while (!ss.eof())
		{
			ss >> temp;
			equation.second.push_back(std::stoi(temp));
		}

		Equations.push_back(equation);
	}
}
void DaySeven::RunAssignment()
{
	long long resultAssignment = 0;

	for (size_t i = 0; i < Equations.size(); i++)
	{
		if (IsEquationPossible(Equations[i].first, Equations[i].second))
		{
			resultAssignment += Equations[i].first;
		}
	}

	std::cout << "Total calibration result: " << resultAssignment << std::endl;
}
void DaySeven::RunBonusAssignment()
{
	long long resultAssignment = 0;
	std::vector<std::string> operators = { "+","*","||" };

	for (size_t i = 0; i < Equations.size(); i++)
	{
		if (IsEquationPossible(Equations[i].first, Equations[i].second, operators))
		{
			resultAssignment += Equations[i].first;
		}
	}

	std::cout << "Total calibration result: " << resultAssignment << std::endl;
}

bool DaySeven::IsEquationPossible(long long expectedResultEquation, std::vector<size_t> numbersEquation)
{
	size_t operatorSlotCount = numbersEquation.size() - 1;

	for (int mask = 0; mask < (1 << operatorSlotCount); mask++)
	{
		long long actualResult = numbersEquation[0];

		for (size_t i = 0; i < operatorSlotCount; i++)
		{
			if (mask & (1 << i))
			{
				actualResult *= numbersEquation[i + 1];
			}
			else
			{
				actualResult += numbersEquation[i + 1];
			}
		}

		if (actualResult == expectedResultEquation)
		{
			return true;
		}
	}

	return false;
}

//TODO: Requires improvement to increase speed
bool DaySeven::IsEquationPossible(long long expectedResultEquation, std::vector<size_t> numbersEquation, std::vector<std::string> operators)
{
	int operatorSlotCount = numbersEquation.size() - 1;
	int totalCombination = 1;

	for (size_t i = 0; i < operatorSlotCount; i++)
	{
		totalCombination *= operators.size();
	}

	for (size_t mask = 0; mask < totalCombination; mask++)
	{
		long long actualResult = numbersEquation[0];
		size_t index = mask;

		for (size_t i = 0; i < operatorSlotCount; i++)
		{
			std::string op = operators[index % operators.size()];

			if (op == "+")
			{
				actualResult *= numbersEquation[i + 1];
				
			}
			else if (op == "*")
			{
				actualResult += numbersEquation[i + 1];
			}
			else if (op == "||")
			{
				// Convert both the integers to string
				std::string s1 = std::to_string(actualResult);
				std::string s2 = std::to_string(numbersEquation[i + 1]);

				// Concatenate both strings
				std::string s = s1 + s2;

				actualResult = stoll(s);
			}

			index /= operators.size();
		}

		if (actualResult == expectedResultEquation)
		{
			return true;
		}
	}

	return false;
}