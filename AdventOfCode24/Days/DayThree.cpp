#include "DayThree.h"
#include <sstream>

DayThree::DayThree(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		Input += ParsedFile[i];
	}
}

void DayThree::Initialize()
{
	std::string startInstruction = "mul(";
	std::string endInstruction = ")";
	std::string doInstruction = "do()";
	std::string dontInstruction = "don't()";

	size_t pos = 0;
	size_t offset = 4;

	//Search for all mul instructions
	pos = Input.find(startInstruction, 0);

	while (pos != std::string::npos)
	{
		MulIntructions.insert({ pos + offset, Input.find(endInstruction, pos) });
		pos = Input.find(startInstruction, pos + 1);
	}

	//Search for dont and do instructions
	pos = Input.find(dontInstruction);

	while (pos != std::string::npos)
	{
		ConditionalInstructions.insert({ pos, Input.find(doInstruction, pos) });
		pos = Input.find(dontInstruction, pos + 1);
	}
}

void DayThree::RunAssignment()
{
	std::cout << "Result of assignment is: " << CalculateResult() << std::endl;
}
void DayThree::RunBonusAssignment()
{
	RunConditionalChecks();

	std::cout << "Updated result of assignment is: " << CalculateResult() << std::endl;
}

void DayThree::RunConditionalChecks()
{
	std::map<size_t, size_t>::iterator conMapIt;
	std::map<size_t, size_t>::iterator mulMapIt;

	for (conMapIt = ConditionalInstructions.begin(); conMapIt != ConditionalInstructions.end();)
	{
		for (mulMapIt = MulIntructions.begin(); mulMapIt != MulIntructions.end();)
		{
			if (mulMapIt->first > conMapIt->second)
			{
				break;
			}

			if (mulMapIt->first > conMapIt->first && mulMapIt->first < conMapIt->second)
			{
				mulMapIt = MulIntructions.erase(mulMapIt);
				continue;
			}

			++mulMapIt;
		}
		
		++conMapIt;
	}
}

int DayThree::CalculateResult()
{
	int result = 0;
	std::map<size_t, size_t>::iterator it;

	for (it = MulIntructions.begin(); it != MulIntructions.end();)
	{
		bool invalid = false;
		std::string tempString = "";

		for (size_t i = it->first; i < it->second; i++)
		{
			if (Input[i] == ',')
			{
				tempString += ' ';
			}
			else if (Input[i] >= '0' && Input[i] <= '9')
			{
				tempString += Input[i];
			}
			else
			{
				invalid = true;
				break;
			}
		}

		if (invalid)
		{
			it = MulIntructions.erase(it);
			continue;
		}

		int firstNumber = -1;
		int secondNumber = -1;
		int found;

		std::stringstream ss;
		std::string temp = "";
		ss << tempString;

		while (!ss.eof())
		{
			ss >> temp;

			if (std::stringstream(temp) >> found)
			{
				if (firstNumber == -1)
				{
					firstNumber = found;
				}
				else
				{
					secondNumber = found;
				}
			}
		}

		if (firstNumber != -1 && secondNumber != -1)
		{
			result += (firstNumber * secondNumber);
		}

		++it;
	}

	return result;
}