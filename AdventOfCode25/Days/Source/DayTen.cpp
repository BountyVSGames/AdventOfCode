#include "../Header/DayTen.h"

DayTen::DayTen(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayTen::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		Machine machine;

		size_t lastCharIndicLight = ParsedFile[i].find(']');

		for (size_t j = 1; j < lastCharIndicLight; j++)
		{
			machine.lightIndications.push_back(ParsedFile[i][j] == '#' ? 1 : 0);
		}

		size_t startIndexWiring = lastCharIndicLight + 3;
		size_t startIndexJoltage = ParsedFile[i].find('{');

		while (startIndexWiring < startIndexJoltage)
		{
			size_t endIndexWiring = ParsedFile[i].find(')', startIndexWiring);
			std::string indexString = ParsedFile[i].substr(startIndexWiring, endIndexWiring - startIndexWiring);

			if (indexString.size() > 1)
			{
				size_t sepIndx = startIndexWiring;
				std::vector<int> schematic;

				while (sepIndx != std::string::npos && sepIndx < endIndexWiring)
				{
					size_t tempSepIndx = ParsedFile[i].find(',', sepIndx + 1);

					if (tempSepIndx > endIndexWiring)
					{
						tempSepIndx = endIndexWiring;
						schematic.push_back(stoi(ParsedFile[i].substr(sepIndx, tempSepIndx - sepIndx)));
					}
					else
					{
						schematic.push_back(stoi(ParsedFile[i].substr(sepIndx, (tempSepIndx - sepIndx))));
					}
 
					sepIndx = tempSepIndx + 1;
				}

				machine.wiringSchematics.push_back(schematic);
			}
			else
			{
				machine.wiringSchematics.push_back({ stoi(indexString) });
			}	
			
			startIndexWiring = endIndexWiring + 3;
		}
		
		AllMachines.push_back(machine);
	}
}

void DayTen::RunAssignment()
{
	for (size_t i = 0; i < AllMachines.size(); i++)
	{
		std::cout << "[";

		for (size_t j = 0; j < AllMachines[i].lightIndications.size(); j++)
		{
			std::cout << AllMachines[i].lightIndications[j];
		}

		std::cout << "] ";

		for (size_t j = 0; j < AllMachines[i].wiringSchematics.size(); j++)
		{
			std::cout << "(";

			for (size_t k = 0; k < AllMachines[i].wiringSchematics[j].size(); k++)
			{
				std::cout << AllMachines[i].wiringSchematics[j][k] << " ";
			}

			std::cout << ") ";
		}

		std::cout << std::endl;
	}
}

void DayTen::RunBonusAssignment()
{

}