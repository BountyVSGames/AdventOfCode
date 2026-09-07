#include "../../Header/Days/DayTwo.h"

DayTwo::DayTwo(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
};

void DayTwo::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		size_t splitIndex = ParsedFile[i].find(':');
		size_t dashIndex = ParsedFile[i].find('-');
		size_t spaceIndex = ParsedFile[i].find_first_of(' ');

		PasswordCheck passwordCheck;

		passwordCheck.minCharLenght = (size_t)std::stoi(ParsedFile[i].substr(0, dashIndex));
		passwordCheck.maxCharLenght = (size_t)std::stoi(ParsedFile[i].substr(dashIndex + 1, spaceIndex - (dashIndex + 1)));
		passwordCheck.charRequirement = ParsedFile[i][spaceIndex + 1];

		for (size_t j = splitIndex; j < ParsedFile[i].size(); j++)
		{
			if (IsCharInRange(ParsedFile[i][j], 97, 122))
			{
				passwordCheck.password = ParsedFile[i].substr(j, ParsedFile[i].size() - j);
				break;
			}
		}

		passwordChecks.push_back(passwordCheck);
	}
}

void DayTwo::RunAssignment()
{
	int validPasswords = 0;

	for (size_t i = 0; i < passwordChecks.size(); i++)
	{
		validPasswords += IsPasswordValidFirstPolicy(passwordChecks[i]);
	}

	std::cout << "Password database contains " << validPasswords << " valid passwords" << std::endl;
}
void DayTwo::RunBonusAssignment()
{
	int validPasswords = 0;

	for (size_t i = 0; i < passwordChecks.size(); i++)
	{
		validPasswords += IsPasswordValidSecondPolicy(passwordChecks[i]);
	}

	std::cout << "Password database contains " << validPasswords << " valid passwords" << std::endl;
}

bool DayTwo::IsPasswordValidFirstPolicy(PasswordCheck passwordCheck)
{
	int charCount = 0;

	for (int i = 0; i < passwordCheck.password.size(); i++)
	{
		if (passwordCheck.password[i] == passwordCheck.charRequirement)
		{
			charCount++;
		}
	}

	return (charCount >= passwordCheck.minCharLenght) && (charCount <= passwordCheck.maxCharLenght);
}
bool DayTwo::IsPasswordValidSecondPolicy(PasswordCheck passwordCheck)
{
	bool firstIndexContainsChar = passwordCheck.password[passwordCheck.minCharLenght - 1] == passwordCheck.charRequirement;
	bool secondIndexContainsChar = passwordCheck.password[passwordCheck.maxCharLenght - 1] == passwordCheck.charRequirement;

	return (firstIndexContainsChar && !secondIndexContainsChar) || (!firstIndexContainsChar && secondIndexContainsChar);
}

bool DayTwo::IsCharInRange(char c, int minCharIndx, int maxCharIndx)
{
	int charIndex = (int)c;
	return ((charIndex >= minCharIndx) && (charIndex <= maxCharIndx));
}