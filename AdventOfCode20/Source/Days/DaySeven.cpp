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

		//Bag that contains the other bags
		std::string ruleKey = ParsedFile[i].substr(numIndex, bagIndex - numIndex);
		std::vector<std::string> ruleValue;

		//Find first contained bag bag
		numIndex = ParsedFile[i].find_first_of("0123456789", numIndex + 1);
		bagIndex = ParsedFile[i].find(" bag", numIndex);

		while (numIndex != std::string::npos)
		{
			ruleValue.push_back(ParsedFile[i].substr(numIndex, bagIndex - numIndex));
			
			//Find next contained bag
			numIndex = ParsedFile[i].find_first_of("0123456789", numIndex + 1);
			bagIndex = ParsedFile[i].find(" bag", numIndex);
		}

		//Add rule if bag contains any other bags
		if (ruleValue.size() > 0)
		{
			bagRules.insert({ ruleKey, ruleValue });
		}
	}
}

void DaySeven::RunAssignment()
{
	std::string bagToFind = "shiny gold";
	std::string bagsFound = "";
	int count = 0;

	GetContainedBagFromRules(bagToFind, bagsFound, count);

	std::cout << "Number of bag color that can eventually contain atleast on " << bagToFind << " bag is " << count << std::endl;
}

void DaySeven::RunBonusAssignment()
{
	std::string bagToFind = "shiny gold";
	int count = 0;

	GetCountContainedInBag(bagToFind, count);
}

void DaySeven::GetContainedBagFromRules(std::string bagName, std::string& bagsFound, int& count)
{
	for (std::map<std::string, std::vector<std::string>>::iterator it = bagRules.begin(); it != bagRules.end(); it++)
	{
		for (size_t j = 0; j < it->second.size(); j++)
		{
			if (it->second[j].substr(2) == bagName && bagsFound.find(it->first) == std::string::npos)
			{
				std::cout << it->first << std::endl;

				bagsFound += it->first;
				++count;
				GetContainedBagFromRules(it->first, bagsFound, count);
			}
		}
	}
}
void DaySeven::GetCountContainedInBag(std::string bagName, int& count)
{
	std::map<std::string, std::vector<std::string>>::iterator bagIt = bagRules.find(bagName);
	int totalCount = 0;

	if (bagIt == bagRules.end())
	{
		return;
	}

	count = 0;

	for (size_t i = 0; i < bagIt->second.size(); i++)
	{
		count += std::stoi(bagIt->second[i].substr(0, 2));
		
		std::string bagName = bagIt->second[i].substr(2);
		std::map<std::string, std::vector<std::string>>::iterator bagInBagIt = bagRules.find(bagName);

		if (bagInBagIt != bagRules.end())
		{
			GetCountContainedInBag(bagName, count);

			totalCount += (std::stoi(bagIt->second[i].substr(0, 2)) + (std::stoi(bagIt->second[i].substr(0, 2)) * count));

			std::cout << std::stoi(bagIt->second[i].substr(0, 2)) << "+" << std::stoi(bagIt->second[i].substr(0, 2)) << "*" << count << std::endl;
			std::cout << totalCount << std::endl;
		}

		
	}

	
}