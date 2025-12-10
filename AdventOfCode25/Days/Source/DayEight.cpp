#include "../Header/DayEight.h"

DayEight::DayEight(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayEight::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		JunctionBox pos = JunctionBox();
		size_t sepIt = 0;
		size_t it = 0;
		
		while (sepIt != std::string::npos)
		{
			size_t nextPos = ParsedFile[i].find(',', sepIt + 1);
			bool lastValue = (nextPos == std::string::npos);

			std::string strValue = lastValue ? ParsedFile[i].substr(sepIt, ParsedFile[i].size() - sepIt)
												: ParsedFile[i].substr(sepIt, nextPos - sepIt);

			pos.coor[it] = std::stod(strValue);
			sepIt = lastValue ? nextPos : nextPos + 1;
			it++;
		}

		AllPos.push_back(pos);
	}

	for (size_t i = 0; i < AllPos.size(); i++)
	{
		for (size_t j = i + 1; j < AllPos.size(); j++)
		{
			double distance = Distance(AllPos[i], AllPos[j]);

			AllPairs.push_back({ i, j, distance });
		}
	}

	QuickSortJunctionPair(AllPairs, 0, (int)AllPairs.size() - 1);
}

void DayEight::RunAssignment()
{
	int max = 1000;
	int it = 0;

	for (size_t i = 0; i < AllPairs.size(); i++)
	{
		int indexContainingA = -1;
		int indexContainingB = -1;

		JunctionBox boxA = AllPos[AllPairs[i].indxBoxA];
		JunctionBox boxB = AllPos[AllPairs[i].indxBoxB];

		if (it == max)
		{
			break;
		}

		for (size_t j = 0; j < AllCircuits.size(); j++)
		{
			bool containsBoxA = (std::find(AllCircuits[j].junBox.begin(), AllCircuits[j].junBox.end(), AllPairs[i].indxBoxA) != AllCircuits[j].junBox.end());
			bool containsBoxB = (std::find(AllCircuits[j].junBox.begin(), AllCircuits[j].junBox.end(), AllPairs[i].indxBoxB) != AllCircuits[j].junBox.end());

			if (containsBoxA && containsBoxB)
			{
				indexContainingA = (int)j;
				indexContainingB = (int)j;
				break;
			}

			if (containsBoxA)
			{
				indexContainingA = (int)j;
			}
			
			if (containsBoxB)
			{
				indexContainingB = (int)j;
			}
		}

		if (indexContainingA == -1 && indexContainingB == -1)
		{
			Circuit cir = Circuit(AllPairs[i].indxBoxA, AllPairs[i].indxBoxB);

			AllCircuits.push_back(cir);

			it++;
		}
		else if (indexContainingA == indexContainingB)
		{
			it++;
		}
		else if (indexContainingA != -1 && indexContainingB == -1)
		{
			AllCircuits[indexContainingA].junBox.push_back(AllPairs[i].indxBoxB);
			it++;
		}
		else if (indexContainingA == -1 && indexContainingB != -1)
		{
			AllCircuits[indexContainingB].junBox.push_back(AllPairs[i].indxBoxA);
			it++;
		}
		else if (indexContainingA != indexContainingB)
		{
			AllCircuits[indexContainingA].junBox.insert(
				AllCircuits[indexContainingA].junBox.end(),
				AllCircuits[indexContainingB].junBox.begin(),
				AllCircuits[indexContainingB].junBox.end());

			AllCircuits.erase(AllCircuits.begin() + indexContainingB);

			it++;
		}
	}

	QuickSortCircuits(AllCircuits, 0, (int)AllCircuits.size() - 1);

	size_t result = AllCircuits[0].junBox.size();

	for (size_t i = 1; i < 3; i++)
	{
		result *= AllCircuits[i].junBox.size();
	}
	
	std::cout << "RESULT: " << result << std::endl;
}

void DayEight::RunBonusAssignment()
{
	//std::vector<JunctionPair> allPairs = AllPairs;

	//for (int i = 0; i < allPairs.size(); i++)
	//{
	//	int indexContainingA = -1;
	//	int indexContainingB = -1;

	//	int circuitSize = AllCircuits.size();

	//	JunctionBox boxA = AllPos[allPairs[i].indxBoxA];
	//	JunctionBox boxB = AllPos[allPairs[i].indxBoxB];

	//	for (size_t j = 0; j < AllCircuits.size(); j++)
	//	{
	//		bool containsBoxA = (std::find(AllCircuits[j].junBox.begin(), AllCircuits[j].junBox.end(), allPairs[i].indxBoxA) != AllCircuits[j].junBox.end());
	//		bool containsBoxB = (std::find(AllCircuits[j].junBox.begin(), AllCircuits[j].junBox.end(), allPairs[i].indxBoxB) != AllCircuits[j].junBox.end());

	//		if (containsBoxA && containsBoxB)
	//		{
	//			indexContainingA = (int)j;
	//			indexContainingB = (int)j;
	//			break;
	//		}

	//		if (containsBoxA)
	//		{
	//			indexContainingA = (int)j;
	//		}

	//		if (containsBoxB)
	//		{
	//			indexContainingB = (int)j;
	//		}
	//	}

	//	if (indexContainingA == -1 && indexContainingB == -1)
	//	{
	//		Circuit cir = Circuit(allPairs[i].indxBoxA, allPairs[i].indxBoxB);

	//		AllCircuits.push_back(cir);
	//	}
	//	else if (indexContainingA != -1 && indexContainingB == -1)
	//	{
	//		AllCircuits[indexContainingA].junBox.push_back(allPairs[i].indxBoxB);
	//	}
	//	else if (indexContainingA == -1 && indexContainingB != -1)
	//	{
	//		AllCircuits[indexContainingB].junBox.push_back(allPairs[i].indxBoxA);
	//	}
	//	else if (indexContainingA != indexContainingB)
	//	{
	//		AllCircuits[indexContainingA].junBox.insert(
	//			AllCircuits[indexContainingA].junBox.end(),
	//			AllCircuits[indexContainingB].junBox.begin(),
	//			AllCircuits[indexContainingB].junBox.end());

	//		AllCircuits.erase(AllCircuits.begin() + indexContainingB);
	//	}

	//	if (AllCircuits.size() == 1)
	//	{
	//		std::cout << "TEST";
	//	}
	//}

	//JunctionBox boxA = AllPos[AllCircuits[0].startBoxA];
	//JunctionBox boxB = AllPos[AllCircuits[0].startBoxB];

	//std::cout << boxA.coor[0] << "." << boxA.coor[1] << "," << boxA.coor[2] << std::endl;
	//std::cout << boxB.coor[0] << "." << boxB.coor[1] << "," << boxB.coor[2] << std::endl;
}

double DayEight::Distance(const JunctionBox& a, const JunctionBox& b)
{
	return std::sqrt((a.coor[0] - b.coor[0]) * (a.coor[0] - b.coor[0]) +
						(a.coor[1] - b.coor[1]) * (a.coor[1] - b.coor[1]) +
						(a.coor[2] - b.coor[2]) * (a.coor[2] - b.coor[2]));
}

void DayEight::QuickSortJunctionPair(std::vector<JunctionPair>& pairsToSort, int left, int right)
{
	if (left < right)
	{
		double pivot = pairsToSort[right].distance;
		int i = (left - 1);

		for (int j = left; j <= right - 1; j++)
		{
			if (pairsToSort[j].distance <= pivot)
			{
				i++;

				JunctionPair temp = pairsToSort[i];
				pairsToSort[i] = pairsToSort[j];
				pairsToSort[j] = temp;
			}
		}

		JunctionPair temp = pairsToSort[i + 1];
		pairsToSort[i + 1] = pairsToSort[right];
		pairsToSort[right] = temp;

		i = i + 1;

		QuickSortJunctionPair(pairsToSort, left, i - 1);
		QuickSortJunctionPair(pairsToSort, i + 1, right);
	}
}

void DayEight::QuickSortCircuits(std::vector<Circuit>& pairsToSort, int left, int right)
{
	if (left < right)
	{
		size_t pivot = pairsToSort[right].junBox.size();
		int i = (left - 1);

		for (int j = left; j <= right - 1; j++)
		{
			if (pairsToSort[j].junBox.size() >= pivot)
			{
				i++;

				Circuit temp = pairsToSort[i];
				pairsToSort[i] = pairsToSort[j];
				pairsToSort[j] = temp;
			}
		}

		Circuit temp = pairsToSort[i + 1];
		pairsToSort[i + 1] = pairsToSort[right];
		pairsToSort[right] = temp;

		i = i + 1;

		QuickSortCircuits(pairsToSort, left, i - 1);
		QuickSortCircuits(pairsToSort, i + 1, right);
	}
}