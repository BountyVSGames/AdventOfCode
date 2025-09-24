#include "DayThree.h"
#include <sstream>

DayThree::DayThree(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{
	result = 0;
}

void DayThree::RunAssignment()
{
	std::string sub = "mul(";
	std::string tempString;
	std::vector<size_t> positions;
	size_t pos = 0;
	size_t finalPos = 0;

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		positions = std::vector<size_t>();
		pos = ParsedFile[i].find(sub,0);

		while (pos != std::string::npos)
		{
			positions.push_back(pos + 4);
			pos = ParsedFile[i].find(sub, pos + 1);
		}

		for (size_t j = 0; j < positions.size(); j++)
		{
			//std::cout << positions[j] << " . " << finalPos << " " << (finalPos - positions[j]) << std::endl;
			//std::cout << ParsedFile[i][positions[j]] << std::endl;
			//std::cout << "po" << std::endl;

			finalPos = 0;
			tempString = "";
			bool invalid = false;

			for (size_t k = 0; k < 8; k++) 
			{
				//std::cout << ParsedFile[i][positions[j] + k];

				if ((ParsedFile[i][positions[j] + k] >= '0' && ParsedFile[i][positions[j] + k] <= '9'))
				{
					tempString += ParsedFile[i][positions[j] + k];
					//std::cout << ParsedFile[i][positions[j] + k];
				}
				else if (ParsedFile[i][positions[j] + k] == ',')
				{
					tempString += " ";
					//std::cout << ParsedFile[i][positions[j] + k];
				}

				if ((ParsedFile[i][positions[j] + k] == ')') && finalPos == 0)
				{
					finalPos = positions[j] + k;
				}
				else if ((ParsedFile[i][positions[j] + k] == ')'))
				{
					positions.erase(positions.begin() + j);
					j--;
					invalid = true;
					break;
				}	
			}

			if (invalid || finalPos == 0)
			{
				//std::cout << "TEST" << std::endl;
				break;
			}

			//std::cout << tempString << std::endl;
			//std::cout << positions[j] << " . " << finalPos << " " << (finalPos - positions[j]) << std::endl;
			//std::cout << ParsedFile[i].substr(positions[j], finalPos - positions[j]) << std::endl;

			tempString += ParsedFile[i][finalPos];

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

			temp = "";

			if (firstNumber != -1 && secondNumber != -1)
			{
				//std::cout << firstNumber << " . " << secondNumber << std::endl << std::endl;
				//std::cout << tempString << " . " << firstNumber << " . " << secondNumber << std::endl;
				result += (firstNumber * secondNumber);
			}
		}
	}

	//std::cout << "Result of assignment is: " << result << std::endl;
}
void DayThree::RunBonusAssignment()
{

}