#pragma once
#include <iostream>
#include <vector>
#include <string>

class Assignment
{
public:
	virtual std::string GetAssignmentName() { return ""; };

	virtual void Initialize() {};
	virtual void RunAssignment() {};
	virtual void RunBonusAssignment() {};
};