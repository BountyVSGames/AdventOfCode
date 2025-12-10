#pragma once
#include "../../Assignment.h"

class DayTen : public Assignment
{
	struct Machine
	{
		std::vector<bool> lightIndications;
		std::vector<std::vector<int>> wiringSchematics;
	};

	public:
		DayTen(std::vector<std::string> parsedFile);

		std::string GetAssignmentName() { return "Day Ten"; };

		void Initialize();
		void RunAssignment();
		void RunBonusAssignment();
private:
	std::vector<Machine> AllMachines;
};

