#pragma once
#include "../../Header/Assignment.h"

struct Passport
{
	int byr;
	int iyr;
	int eyr;
	int hgt;

	std::string hcl;
	std::string ecl;

	int pid;
};

class DayFour : public Assignment
{
public:
	DayFour(std::vector<std::string> parsedFile);

	std::string GetAssignmentName() { return "Day Four"; };

	void Initialize();
	void RunAssignment();
	void RunBonusAssignment();
private:
	bool DoesPassportContainRequirements(std::string& passport);
	bool DoesPassportContainValidInformation(std::string& passport);
	bool ValidatePassportField(std::string keyword, std::string value);

	std::vector<std::string> allPassports;
	std::vector<std::string> keywordsRequired;
	std::vector<std::string> validEyeColours;
};

