#include "DayTwo.h"
#include <sstream>

DayTwo::DayTwo(std::vector<std::string> parsedFile)
{
	//String Stream used by https://www.geeksforgeeks.org/extract-integers-string-c/
	SaveReports = 0;

	std::vector<int> result;
	
	std::string temp;

	int found = 0;

	bool increasing = false;
	bool decreasing = false;

	bool unsafe = false;

	for (size_t i = 0; i < parsedFile.size(); i++)
	{
		std::stringstream ss;
		ss << parsedFile[i];
		result.clear();

		increasing = false;
		decreasing = false;
		unsafe = false;

		temp = "";
		found = 0;

		while (!ss.eof())
		{
			ss >> temp;

			if (std::stringstream(temp) >> found)
			{
				result.push_back(found);

				if (result.size() > 2)
				{
					if (decreasing && ((found >= result[result.size() - 2]) || (abs(found - result[result.size() - 2]) > 3)))
					{
						unsafe = true;
						break;
					}
					else if (increasing && ((found <= result[result.size() - 2]) || (abs(found - result[result.size() - 2]) > 3)))
					{
						unsafe = true;
						break;
					}
				}
				else if (result.size() == 2)
				{
					if ((found < result[result.size() - 2]) && (abs(found - result[result.size() - 2]) <= 3))
					{
						decreasing = true;
					}
					else if ((found > result[result.size() - 2]) && (abs(found - result[result.size() - 2]) <= 3))
					{
						increasing = true;
					}
					else
					{
						unsafe = true;
						break;
					}
				}	
			}

			temp = "";
			found = 0;
		}

		result.clear();

		if (!unsafe)
		{
			SaveReports++;
		}
		else
		{
			UnsaveReports.push_back(parsedFile[i]);
		}
	}
}

void DayTwo::RunAssignment()
{
	std::cout << "Result is: " << SaveReports << " save reports" << std::endl;
}
void DayTwo::RunBonusAssignment()
{
	std::cout << "Result is: " << UpdatedSaveReports << " save reports" << std::endl;
}