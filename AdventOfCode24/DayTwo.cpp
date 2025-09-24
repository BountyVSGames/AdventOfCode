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

		int found = 0;

		std::string temp = "";

		while (!ss.eof())
		{
			ss >> temp;

			if (std::stringstream(temp) >> found)
			{
				result.push_back(found);	
			}

			temp = "";
			found = 0;
		}

		if (!RunRuleSet(result))
		{
			Reports.push_back(result);
			continue;
		}

		SaveReports++;
	}
}

void DayTwo::RunAssignment()
{
	std::cout << "Result is: " << SaveReports << " save reports" << std::endl;
}
void DayTwo::RunBonusAssignment()
{
	for (size_t i = Reports.size(); i > 0; i--)
	{
		if (!ContainsSingleBadLevel(0, Reports[i - 1]))
		{
			Reports.erase(Reports.begin() + (i - 1));
		}
	}

	std::cout << "Result is: " << Reports.size() << " updated safe reports." << std::endl;
	std::cout << "New size: " << SaveReports + Reports.size() << std::endl;
}

bool DayTwo::RunRuleSet(std::vector<int> report)
{
	bool decreasing = false;
	bool increasing = false;

	for (int i = 0; i < report.size() - 1; i++)
	{
		if (i > 1)
		{
			if (decreasing && (report[i] >= report[i - 1]))
			{
				return false;
			}
			else if (increasing && (report[i] <= report[i - 1]))
			{
				return false;
			}

			if ((abs(report[i - 1] - report[i]) > 3) || (abs(report[i - 1] - report[i]) == 0))
			{
				return false;
			}
		}
		else if (i == 1)
		{
			if (abs(report[i - 1] - report[i] > 3) || abs(report[i - 1] - report[i] == 0))
			{
				return false;
			}

			if (report[i + 1] < report[i])
			{
				decreasing = true;
			}
			else if (report[i + 1] > report[i])
			{
				increasing = true;
			}
			else
			{
				return false;
			}
		}
		else if(abs(report[i + 1] - report[i]) > 3 || abs(report[i + 1] - report[i]) == 0)
		{
			return false;
		}
	}

	return true;
}

bool DayTwo::ContainsSingleBadLevel(int iterator, std::vector<int> report)
{
	std::vector<int> tempReport = report;
	report.erase(report.begin() + iterator);

	if (!RunRuleSet(tempReport) && iterator < report.size())
	{
		return ContainsSingleBadLevel(iterator++, report);
	}

	return true;
}