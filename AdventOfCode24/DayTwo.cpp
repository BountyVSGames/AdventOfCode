#include "DayTwo.h"
#include <sstream>

DayTwo::DayTwo(std::vector<std::string> parsedFile)
{
	//String Stream used by https://www.geeksforgeeks.org/extract-integers-string-c/
	SaveReports = 0;

	for (size_t i = 0; i < parsedFile.size(); i++)
	{
		std::stringstream ss;
		ss << parsedFile[i];

		std::vector<int> result;

		bool increasing = false;
		bool decreasing = false;
		bool unsafe = false;
		bool doubleUnsafe = false;

		int found = 0;

		std::string temp = "";

		while (!ss.eof())
		{
			ss >> temp;

			if (std::stringstream(temp) >> found)
			{
				if (result.size() > 1)
				{
					if (decreasing && ((found >= result[result.size() - 1]) || (abs(found - result[result.size() - 1]) > 3) || (abs(found - result[result.size() - 1]) == 0)))
					{
						if (!unsafe)
						{
							unsafe = true;
							continue;
						}
						else if (unsafe && !doubleUnsafe)
						{
							doubleUnsafe = true;
						}
					}
					else if (increasing && ((found <= result[result.size() - 1]) || (abs(found - result[result.size() - 1]) > 3) || (abs(found - result[result.size() - 1]) == 0)))
					{
						if (!unsafe)
						{
							unsafe = true;
							continue;
						}
						else if(unsafe && !doubleUnsafe)
						{
							doubleUnsafe = true;
							break;
						}
					}
				}
				else if (result.size() == 1)
				{
					if ((found < result[result.size() - 1]) && (abs(found - result[result.size() - 1]) <= 3))
					{
						decreasing = true;
					}
					else if ((found > result[result.size() - 1]) && (abs(found - result[result.size() - 1]) <= 3))
					{
						increasing = true;
					}
					else if (!unsafe)
					{
						unsafe = true;
						continue;
					}
					else if (unsafe)
					{
						doubleUnsafe = true;
						std::cout << "UNSAFE" << std::endl;
						break;
					}
				}

				result.push_back(found);
			}

			temp = "";
			found = 0;
		}

		if (!unsafe)
		{
			SaveReports++;
		}
		else if(unsafe && !doubleUnsafe)
		{
			OneErrorReports++;
		}
		else if (unsafe && doubleUnsafe)
		{
			for (size_t i = 0; i < result.size(); i++)
			{
				std::cout << result[i] << " ";
			}

			std::cout << std::endl << parsedFile[i] << std::endl;
		}
	}
}

void DayTwo::RunAssignment()
{
	std::cout << "Result is: " << SaveReports << " save reports" << std::endl;
}
void DayTwo::RunBonusAssignment()
{
	std::cout << "Result is: " << OneErrorReports << " updated safe reports." << std::endl;
	std::cout << "New size: " << SaveReports + OneErrorReports << std::endl;
}