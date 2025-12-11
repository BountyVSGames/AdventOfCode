#include "../Header/DayEleven.h"

DayEleven::DayEleven(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayEleven::Initialize()
{
	std::map<std::string, int> labelToIndex;
	size_t deviceSplitIndex = ParsedFile[0].find(':');

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::string deviceString = ParsedFile[i].substr(0, deviceSplitIndex);

		if (deviceString == "you")
		{
			StartDeviceIndex = (int)i;
		}
		else if (deviceString == "svr")
		{
			StartBonusDeviceIndex = (int)i;
		}

		labelToIndex.insert({ deviceString, (int)i });
	}

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::vector<int> connectionPaths;
		size_t outputSplitIndex = deviceSplitIndex + 2;
		bool lastOutputValue = false;

		while (!lastOutputValue)
		{
			size_t nextOutputSplitIndex = ParsedFile[i].find(' ', outputSplitIndex + 1);
			lastOutputValue = nextOutputSplitIndex == std::string::npos;
			size_t size = (lastOutputValue ? (ParsedFile[i].size() - outputSplitIndex) : (nextOutputSplitIndex - outputSplitIndex));
			std::string outputString = ParsedFile[i].substr(outputSplitIndex, size);
			
			if (outputString == "out")
			{
				connectionPaths.push_back(-1);
				break;
			}
			
			std::map<std::string, int>::iterator it = labelToIndex.find(outputString);
			connectionPaths.push_back(it->second);

			outputSplitIndex = nextOutputSplitIndex + 1;
		}

		AllConnectionPaths.insert({ (int)i, connectionPaths });
	}
}

void DayEleven::RunAssignment()
{
	std::map<int, std::vector<int>>::iterator it;
	int allPaths = 0;

	if (StartDeviceIndex != -1)
	{
		GetAllPaths(StartDeviceIndex, allPaths);
	}
	
	std::cout << "There are a total of " << allPaths << " paths." << std::endl;
}

void DayEleven::RunBonusAssignment()
{
	std::map<int, std::vector<int>>::iterator it;
	int allPaths = 0;
	std::vector<int> paths;

	GetAllPaths(StartBonusDeviceIndex, allPaths);

	std::cout << "There are a total of " << allPaths << " paths." << std::endl;
}

void DayEleven::GetAllPaths(int index, int& allPaths)
{
	std::unordered_map<int, std::vector<int>>::iterator it = AllConnectionPaths.find(index);

	for(int child : it->second)
	{
		if (child == -1) 
		{
			allPaths++;
		}
		else
		{
			GetAllPaths(child, allPaths);
		}
	}
}