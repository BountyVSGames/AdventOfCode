#include "../Header/DayEight.h"

DayEight::DayEight(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayEight::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		Vec3 pos = Vec3();
		size_t sepIt = 0;
		size_t it = 0;
		
		while (sepIt != std::string::npos)
		{
			size_t nextPos = ParsedFile[i].find(',', sepIt + 1);
			bool lastValue = (nextPos == std::string::npos);

			std::string strValue = lastValue ? ParsedFile[i].substr(sepIt, ParsedFile[i].size() - sepIt)
												: ParsedFile[i].substr(sepIt, nextPos - sepIt);

			pos.coor[it] = std::stoi(strValue);
			sepIt = lastValue ? nextPos : nextPos + 1;
			it++;
		}

		AllPos.push_back(pos);
	}
}

void DayEight::RunAssignment()
{
	for (size_t i = 0; i < AllPos.size(); i++)
	{
		Vec3 target;
		Circuit* ciruit = new Circuit();

		ciruit->JunctionBoxes.push_back(AllPos[i]);
		AllPos[i].circuit = ciruit;

		while (GetClosestBox(AllPos[i], target) < 350)
		{
			if (target == Vec3())
			{
				break;
			}

			std::cout << "[" << AllPos[i].coor[0] << "," << AllPos[i].coor[1] << "," << AllPos[i].coor[2] << "] > " <<
				"[" << target.coor[0] << "," << target.coor[1] << "," << target.coor[2] << "]" << std::endl;
				

			AllPos[i].circuit->JunctionBoxes.push_back(target);
			target.circuit = AllPos[i].circuit;
		}
	}

	//Vec3 closestBox = GetClosestBox(AllPos[1]);

	//std::cout << std::endl;
	//std::cout << AllPos[0].coor[0] << "," << AllPos[0].coor[1] << "," << AllPos[0].coor[2] << std::endl;
	//std::cout << closestBox.coor[0] << "," << closestBox.coor[1] << "," << closestBox.coor[2] << std::endl;

	//Circuit* circuit = new Circuit();
	//circuit->JunctionBoxes.push_back(AllPos[0]);
	//circuit->JunctionBoxes.push_back(closestBox);
	//
	//AllPos[0].circuit = circuit;
	//closestBox.circuit = circuit;

	//closestBox = GetClosestBox(AllPos[0]);
	//std::cout << std::endl;
	//std::cout << AllPos[0].coor[0] << "," << AllPos[0].coor[1] << "," << AllPos[0].coor[2] << std::endl;
	//std::cout << closestBox.coor[0] << "," << closestBox.coor[1] << "," << closestBox.coor[2] << std::endl;

	//if (AllPos[0].circuit != nullptr)
	//{
	//	AllPos[0].circuit->JunctionBoxes.push_back(closestBox);
	//	closestBox.circuit = AllPos[0].circuit;
	//}

}

void DayEight::RunBonusAssignment()
{

}

double DayEight::GetClosestBox(const Vec3& target, Vec3& closestBox)
{
	double dist = std::numeric_limits<double>::max();

	for (size_t i = 0; i < AllPos.size(); i++)
	{
		if (AllPos[i] == target)
		{
			continue;
		}

		if (target.circuit != nullptr)
		{
			const std::vector<Vec3>& other = target.circuit->JunctionBoxes;

			if (std::find(other.begin(), other.end(), AllPos[i]) != other.end())
			{
				continue;
			}
		}

		double distToTarget = Distance(target, AllPos[i]);

		if (distToTarget < dist)
		{
			dist = distToTarget;
			closestBox = AllPos[i];
		}
	}

	return dist;
}

double DayEight::Distance(const Vec3& a, const Vec3& b)
{
	return std::sqrt((a.coor[0] - b.coor[0]) * (a.coor[0] - b.coor[0]) +
						(a.coor[1] - b.coor[1]) * (a.coor[1] - b.coor[1]) +
						(a.coor[2] - b.coor[2]) * (a.coor[2] - b.coor[2]));
}