#include "DayTwo.h"
#include <sstream>

DayTwo::DayTwo(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
	SaveReports = 0;
}

void DayTwo::Initialize()
{
	//String Stream used by https://www.geeksforgeeks.org/extract-integers-string-c/
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::stringstream ss;
		ss << ParsedFile[i];

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
	std::cout << "Updated safe reports: " << SaveReports + Reports.size() << std::endl;
}

bool DayTwo::RunRuleSet(std::vector<int> report)
{
	bool decreasing = false;
	bool increasing = false;

	for (int i = 0; i < report.size(); i++)
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

			if (report[i] < report[i - 1])
			{
				decreasing = true;
			}
			else if (report[i] > report[i - 1])
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
	if (iterator >= report.size())
	{
		return false;
	}

	std::vector<int> tempReport = report;
	tempReport.erase(tempReport.begin() + iterator);

	if (!RunRuleSet(tempReport))
	{
		return ContainsSingleBadLevel(iterator + 1, report);
	}

	return true;
}