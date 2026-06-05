#include "DayNineteen.h"

DayNineteen::DayNineteen(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayNineteen::Initialize()
{
	size_t it = 0;
	size_t nextIt = ParsedFile[0].find(',');

	while (nextIt != std::string::npos)
	{
		patterns.push_back(ParsedFile[0].substr(it, nextIt - it));

		it = nextIt + 2;
		nextIt = ParsedFile[0].find(',', it + 1);

		if (nextIt == std::string::npos)
		{
			patterns.push_back(ParsedFile[0].substr(it, ParsedFile[0].size() - it));
		}
	}
}
void DayNineteen::RunAssignment()
{
	int possiblePatterns = 0;

	for (size_t i = 2; i < ParsedFile.size(); i++)
	{
		std::string tempString = ParsedFile[i];

		bool patternFound = true;
		size_t startPatternIndex = 0;

		std::cout << tempString << " ";

		while (patternFound && tempString.size() > 0)
		{
			std::string pattern = "";

			for (size_t j = 0; j < patterns.size(); j++)
			{
				size_t tempStartIndex = 0;

				if (FindPatternInString(tempString, patterns[j], tempStartIndex))
				{
					if (patterns[j].size() >= pattern.size())
					{
						pattern = patterns[j];
						startPatternIndex = tempStartIndex;
					}
				}
			}

			if (pattern == "")
			{
				patternFound = false;
			}

			std::cout << pattern << " . ";

			if (pattern.size() == 1)
			{
				tempString.erase(tempString.begin() + startPatternIndex);
			}
			else
			{
				tempString.erase(startPatternIndex, pattern.size());
			}
		}

		std::cout << std::endl;

		if (patternFound)
		{
			possiblePatterns++;
		}
	}

	std::cout << possiblePatterns << " designs are possible" << std::endl;
}
void DayNineteen::RunBonusAssignment()
{

}

bool DayNineteen::FindPatternInString(std::string& string, std::string& pattern, size_t& indexPatternOnString)
{
	std::string tempString = "";

	if (string == pattern)
	{
		indexPatternOnString = 0;
		return true;
	}

	if (string.size() < pattern.size())
	{
		return false;
	}

	for (int i = 0; i < (string.length() - pattern.length()); i++)
	{
		for (size_t j = 0; j < pattern.size();  j++)
		{
			if (string[i + j] != pattern[j])
			{
				break;
			}

			tempString += string[i + j];

			if (tempString == pattern)
			{
				indexPatternOnString = i;

				return true;
			}
		}

		tempString = "";
	}

	return false;
}
