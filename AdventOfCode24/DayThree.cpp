#include "DayThree.h"
#include <map>
#include <sstream>

DayThree::DayThree(std::vector<std::string> parsedFile) : ParsedFile(parsedFile)
{
	result = 0;
}

void DayThree::RunAssignment()
{
	std::string startSub = "mul(";
	std::string endSub = ")";
	
	size_t pos = 0;
	size_t offset = 4;

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::map<size_t, size_t> mapPos;
		pos = ParsedFile[i].find(startSub,0);

		while (pos != std::string::npos)
		{
			mapPos.insert({ pos + offset, ParsedFile[i].find(endSub, pos) });
			pos = ParsedFile[i].find(startSub, pos + 1);
		}

		std::map<size_t, size_t>::iterator it;
		for(it = mapPos.begin(); it != mapPos.end();)
		{
			bool invalid = false;
			std::string tempString = "";

			for (int j = it->first; j < it->second; j++)
			{
				if (ParsedFile[i][j] == ',')
				{
					tempString += ' ';
				}
				else if (ParsedFile[i][j] >= '0' && ParsedFile[i][j] <= '9')
				{
					tempString += ParsedFile[i][j];
				}
				else
				{
					invalid = true;
					break;
				}		
			}

			if (invalid)
			{		
				it = mapPos.erase(it);
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
	}

	std::cout << "Result of assignment is: " << result << std::endl;
}
void DayThree::RunBonusAssignment()
{

}