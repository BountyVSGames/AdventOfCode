#pragma once
#include <iostream>
#include <vector>
#include <string>

class Assignment
{
	public:
		Assignment(std::vector<std::string> parsedFile);

		virtual std::string GetAssignmentName() { return ""; };

		virtual void Initialize() {};
		virtual void RunAssignment() {};
		virtual void RunBonusAssignment() {};
	protected:
		std::vector<std::string> ParsedFile;
};

