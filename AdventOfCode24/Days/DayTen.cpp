#include "DayTen.h"

DayTen::DayTen(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayTen::Initialize()
{
	for (size_t y = 0; y < ParsedFile.size(); y++)
	{
		std::vector<Node> rowNodes;

		for (size_t x = 0; x < ParsedFile[y].size(); x++)
		{
			int value = ParsedFile[y][x] - '0';
			rowNodes.push_back(Node(value));

			//std::cout << value;

			if (ParsedFile[y][x] == '0')
			{
				TrailHeadCoor.push_back({ (int)y,(int)x });
				continue;
			}
			else if (ParsedFile[y][x] == '9')
			{
				EndTrailCoor.push_back({ (int)y, (int)x });
				continue;
			}

		}

		Nodes.push_back(rowNodes);

		//std::cout << std::endl;
	}

	

	for (int y = 0; y < Nodes.size(); y++)
	{
		for (int x = 0; x < Nodes[y].size(); x++)
		{
			int minX = x - 1 < 0 ? x : x - 1;
			int maxX = x + 1 > Nodes[y].size() - 1 ? x : x + 1;
			int minY = y - 1 < 0 ? y : y - 1;
			int maxY = y + 1 > Nodes.size() - 1 ? y : y + 1;

			Node& currentNode = Nodes[y][x];
			int expectedValue = Nodes[y][x].Value + 1;

			if (Nodes[y][minX] != currentNode && Nodes[y][minX].Value == expectedValue)
			{
				currentNode.Neighbours.push_back(Nodes[y][minX]);
			}
			if (Nodes[y][maxX] != currentNode && Nodes[y][maxX].Value == expectedValue)
			{
				currentNode.Neighbours.push_back(Nodes[y][maxX]);
			}
			if (Nodes[minY][x] != currentNode && Nodes[minY][x].Value == expectedValue)
			{
				currentNode.Neighbours.push_back(Nodes[minY][x]);
			}
			if (Nodes[maxY][x] != currentNode && Nodes[maxY][x].Value == expectedValue)
			{
				currentNode.Neighbours.push_back(Nodes[maxY][x]);
			}

		}
	}

	std::cout << std::endl << std::endl;

	for (size_t y = 0; y < Nodes.size(); y++)
	{
		for (size_t x = 0; x < Nodes[y].size(); x++)
		{
			if (Nodes[y][x].Neighbours.size() > 0 || Nodes[y][x].Value == 9)
			{
				std::cout << Nodes[y][x].Value;
				continue;
			}
			
			std::cout << ".";
		}

		std::cout << std::endl;
	}
}

void DayTen::RunAssignment()
{
	int totalTrialsScore = 0;

	for (size_t i = 0; i < TrailHeadCoor.size(); i++)
	{
		totalTrialsScore += CalculatePossibleTrailFromHead(TrailHeadCoor[i]);
	}

	std::cout << "Sum of the scored of all trailheads is: " << totalTrialsScore << std::endl;
}

void DayTen::RunBonusAssignment()
{

}

int DayTen::CalculatePossibleTrailFromHead(std::pair<int, int> startTrailCoor)
{
	return 0;
}

bool DayTen::ContainsNode(std::vector<Node>& nodes, Node& nodeToFind)
{
	for (size_t i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == nodeToFind)
		{
			return true;
		}
	}

	return false;
}