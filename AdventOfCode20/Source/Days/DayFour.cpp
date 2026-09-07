#include "../../Header/Days/DayFour.h"

DayFour::DayFour(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
	keywordsRequired = { "byr","iyr","eyr", "hgt", "hcl",
						"ecl", "pid" };
	validEyeColours = { "amb", "blu", "brn", "grn", "gry",
						"hzl", "oth" };
}

void DayFour::Initialize()
{
	std::string passport = "";

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		if (ParsedFile[i].empty())
		{
			allPassports.push_back(passport);
			passport = "";
			continue;
		}

		passport += (passport == "" ? ParsedFile[i] : " " + ParsedFile[i]);

		if (i == (ParsedFile.size() - 1))
		{
			allPassports.push_back(passport);
		}
	}
}

void DayFour::RunAssignment()
{
	for (int i = (int)allPassports.size() - 1; i >= 0; i--)
	{
		if (!DoesPassportContainRequirements(allPassports[i]))
		{
			allPassports.erase(allPassports.begin() + i);
		};
	}

	std::cout << "The number of valid passports are: " << allPassports.size() << std::endl;
}

void DayFour::RunBonusAssignment()
{
	for (int i = (int)allPassports.size() - 1; i >= 0; i--)
	{
		if (!DoesPassportContainValidInformation(allPassports[i]))
		{
			allPassports.erase(allPassports.begin() + i);
		}
	}

	std::cout << "The number of valid passports are: " << allPassports.size() << std::endl;
}

bool DayFour::DoesPassportContainRequirements(std::string& passport)
{
	std::vector<std::string> keywordsFound;

	for (size_t i = 0; i < keywordsRequired.size(); i++)
	{
		if (passport.find(keywordsRequired[i]) == std::string::npos)
		{
			return false;
		}
	
		keywordsFound.push_back(keywordsRequired[i]);
	}

	return keywordsFound.size() == keywordsRequired.size();
}
bool DayFour::DoesPassportContainValidInformation(std::string& passport)
{
	size_t indx = 0;

	while (indx != std::string::npos)
	{
		size_t divIndx = passport.find(':', indx + 1);
		size_t nextIndx = passport.find(' ', divIndx);

		std::string keyword = passport.substr(indx, divIndx - indx);

		if (!ValidatePassportField(passport.substr(indx, divIndx - indx), passport.substr(divIndx + 1, nextIndx - (divIndx + 1))))
		{
			return false;
		}

		indx = nextIndx == std::string::npos ? nextIndx : nextIndx + 1;
	}

	return true;;
}

bool DayFour::ValidatePassportField(std::string keyword, std::string value)
{
	if (keyword == "byr")
	{
		int intValue = std::stoi(value);
		return intValue >= 1920 && intValue <= 2002;
	}
	else if (keyword == "iyr")
	{
		int intValue = std::stoi(value);
		return intValue >= 2010 && intValue <= 2020;
	}
	else if (keyword == "eyr")
	{
		int intValue = std::stoi(value);
		return intValue >= 2020 && intValue <= 2030;
	}
	else if (keyword == "hgt")
	{
		if (value.size() == 2)
		{
			return false;
		}

		std::string cmOrIn = value.substr(value.size() - 2, 2);
		int intValue = std::stoi(value.substr(0, value.size() - 2));

		if (cmOrIn == "cm")
		{
			return intValue >= 150 && intValue <= 193;
		}
		else if (cmOrIn == "in")
		{
			return intValue >= 59 && intValue <= 76;
		}

		return false;
	}
	else if (keyword == "hcl")
	{
		if (value[0] != '#' || value.size() != 7)
		{
			return false;
		}

		for (size_t i = 1; i < value.size(); i++)
		{
			char valueChar = value[i];

			if (valueChar < 48 || (valueChar > 57 && valueChar < 97) || valueChar > 102)
			{
				return false;
			}
		}

		return true;
	}
	else if (keyword == "ecl")
	{
		for (size_t i = 0; i < validEyeColours.size(); i++)
		{
			if (validEyeColours[i] == value)
			{
				return true;
			}
		}

		return false;
	}
	else if (keyword == "pid")
	{
		if (value.size() != 9)
		{
			return false;
		}

		for (size_t i = 0; i < value.size(); i++)
		{
			if (!std::isdigit(value[i]))
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		return keyword == "cid";
	}
}