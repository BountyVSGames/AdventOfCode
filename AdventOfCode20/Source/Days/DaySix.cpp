#include "../../Header/Days/DaySix.h"

DaySix::DaySix(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DaySix::Initialize()
{
	CustomsForm customsForm = {};

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		if (ParsedFile[i] == "")
		{
			customForms.push_back(customsForm);
			customsForm = {};

			continue;
		}
		
		for (size_t j = 0; j < ParsedFile[i].size(); j++)
		{
			if (customsForm.answerStringFiltered.find(ParsedFile[i][j]) == std::string::npos)
			{
				customsForm.answerStringFiltered += ParsedFile[i][j];
			}

			std::map<char,int>::iterator it = customsForm.countPerChar.find(ParsedFile[i][j]);

			if (it != customsForm.countPerChar.end())
			{
				it->second += 1;
			}
			else
			{
				customsForm.countPerChar.insert({ ParsedFile[i][j],1 });
			}
		}

		customsForm.personCount++;
	}

	customForms.push_back(customsForm);
}

void DaySix::RunAssignment()
{
	size_t sumCount = 0;

	for (size_t i = 0; i < customForms.size(); i++)
	{
		sumCount += customForms[i].answerStringFiltered.size();
	}

	std::cout << "Sum of these counts is " << sumCount << std::endl;
}

void DaySix::RunBonusAssignment()
{
	size_t count = 0;

	for (size_t i = 0; i < customForms.size(); i++)
	{
		for (std::map<char,int>::iterator it = customForms[i].countPerChar.begin(); it != customForms[i].countPerChar.end(); it++)
		{
			if (it->second == customForms[i].personCount)
			{
				count++;
			}
		}
	}

	std::cout << "Sum of these counts is " << count << std::endl;
}