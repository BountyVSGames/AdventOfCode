#include "DaySeven.h"
#include <sstream>

DaySeven::DaySeven(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{
	result = 0;
}

void DaySeven::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		size_t resultEquation = 0;
		std::vector<size_t> numbersEquation;

		size_t split = ParsedFile[i].find(':');
		resultEquation = std::stoi(ParsedFile[i].substr(0, split));

		std::stringstream ss;
		std::string temp = "";
		int found = 0;

		ss << ParsedFile[i].substr(split + 2);
		
		while (!ss.eof())
		{
			ss >> temp;
			numbersEquation.push_back(std::stoi(temp));
		}

		if (IsEquationPossible(resultEquation, numbersEquation))
		{
			result += resultEquation;
		}
	}
}
void DaySeven::RunAssignment()
{
	std::cout << "Total calibration result: " << result << std::endl;
}
void DaySeven::RunBonusAssignment()
{

}

bool DaySeven::IsEquationPossible(size_t expectedResultEquation, std::vector<size_t> numbersEquation)
{
	for (size_t i = 0; i < (numbersEquation.size() - 1)  * 2; i++)
	{
		std::cout << "Test";
	}

	std::cout << std::endl;


	size_t resultEquation = 0;

	if (resultEquation != expectedResultEquation)
	{
		return false;
	}

	return true;
}