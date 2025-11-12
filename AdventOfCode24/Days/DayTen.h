#pragma once
#include "../Assignment.h"

class DayTen : public Assignment
{
	struct Node
	{
		Node(int value) : Value(value) {};

		int Value;
		std::vector<Node> Neighbours;

		bool operator==(const Node& other) const
		{
			return Value == other.Value;
		}
		bool operator!=(const Node& other) const
		{
			return Value != other.Value;
		}
	};

public:
	DayTen(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Ten"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
	
private:
	int CalculatePossibleTrailFromHead(std::pair<int, int> startTrailCoor);

	std::vector<std::pair<int, int>> TrailHeadCoor;
	std::vector<std::pair<int, int>> EndTrailCoor;

	std::vector<std::vector<Node>> Nodes;

	bool ContainsNode(std::vector<Node>& nodes, Node& nodeToFind);
};

