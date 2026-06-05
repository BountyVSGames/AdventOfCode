#include "../../Header/Days/DayTwo.h"

DayTwo::DayTwo(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{
};

void DayTwo::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		int splitIndex = ParsedFile[i].find(':');

		for (size_t j = 0; j < splitIndex; j++)
		{
			std::cout << ParsedFile[i][j];
		}

		for (size_t j = splitIndex; j < ParsedFile[i].size(); j++)
		{
			if (IsCharInRange(ParsedFile[i][j], 97, 122))
			{
				std::string test = ParsedFile[i].substr(j, ParsedFile[i].size() - j);
				std::cout << test << std::endl;
				break;
			}
		}
	}
}

void DayTwo::RunAssignment()
{

}
void DayTwo::RunBonusAssignment()
{

}

bool DayTwo::IsCharInRange(char c, int minCharIndx, int maxCharIndx)
{
	int charIndex = (int)c;
	return ((charIndex >= minCharIndx) && (charIndex <= maxCharIndx));
}