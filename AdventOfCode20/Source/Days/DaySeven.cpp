#include "../../Header/Days/DaySeven.h"

DaySeven::DaySeven(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DaySeven::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		size_t numIndex = 0;
		size_t bagIndex = ParsedFile[i].find(" bag");

		std::string ruleKey = ParsedFile[i].substr(numIndex, bagIndex - numIndex);
		std::vector<std::string> ruleValue;

		numIndex = ParsedFile[i].find_first_of("0123456789", numIndex + 1);
		bagIndex = ParsedFile[i].find(" bag", numIndex);

		while (numIndex != std::string::npos)
		{
			ruleValue.push_back(ParsedFile[i].substr(numIndex, bagIndex - numIndex));

			numIndex = ParsedFile[i].find_first_of("0123456789", numIndex + 1);
			bagIndex = ParsedFile[i].find(" bag", numIndex);
		}

		if (ruleValue.size() > 0)
		{
			bagRules.insert({ ruleKey, ruleValue });
		}
	}
}

void DaySeven::RunAssignment()
{
	for (std::map<std::string, std::vector<std::string>>::iterator it = bagRules.begin(); it != bagRules.end(); it++)
	{
		std::cout << it->first << " : ";

		for (size_t j = 0; j < it->second.size(); j++)
		{
			std::cout << it->second[j] << " ";
		}
		
		std::cout << std::endl;
	}
}

void DaySeven::RunBonusAssignment()
{

}