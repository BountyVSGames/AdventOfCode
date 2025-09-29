#include "DayThree.h"
#include <sstream>

DayThree::DayThree(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		Input += ParsedFile[i];
	}

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

	pos = Input.find(dontInstruction);
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

}

int DayThree::CalculateResult()
{
	int result = 0;
	std::map<size_t, size_t>::iterator it;

	for (it = MulIntructions.begin(); it != MulIntructions.end();)
	{
		bool invalid = false;
		std::string tempString = "";

		for (int i = it->first; i < it->second; i++)
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