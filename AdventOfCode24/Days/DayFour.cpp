#include "DayFour.h"

DayFour::DayFour(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayFour::Initialize()
{
	for (int y = 0; y < ParsedFile.size(); y++)
	{
		for (int x = 0; x < ParsedFile[y].size(); x++)
		{
			if (ParsedFile[y][x] == 'X')
			{
				XCoordinates.push_back({ y, x });
			}
			else if (ParsedFile[y][x] == 'A')
			{
				ACoordinates.push_back({ y,x });
			}
		}
	}
}

void DayFour::RunAssignment()
{
	std::string wordToFind = "XMAS";
	int result = 0;

	for (size_t i = 0; i < XCoordinates.size(); i++)
	{
		std::string output = "X";

		int y = XCoordinates[i].first;
		int x = XCoordinates[i].second;

		//Top
		if ((y - 3) >= 0)
		{
			output += ParsedFile[y - 1][x];
			output += ParsedFile[y - 2][x];
			output += ParsedFile[y - 3][x];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}
		//Top Right
		if ((y - 3) >= 0 && (x + 3) < ParsedFile[y].size())
		{
			output += ParsedFile[y - 1][x + 1];
			output += ParsedFile[y - 2][x + 2];
			output += ParsedFile[y - 3][x + 3];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}

		//Right
		if ((x + 3) < ParsedFile[y].size())
		{
			output += ParsedFile[y][x + 1];
			output += ParsedFile[y][x + 2];
			output += ParsedFile[y][x + 3];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}

		//Bottom Right
		if ((y + 3) < ParsedFile.size() && (x + 3) < ParsedFile[y].size())
		{
			output += ParsedFile[y + 1][x + 1];
			output += ParsedFile[y + 2][x + 2];
			output += ParsedFile[y + 3][x + 3];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}
		//Bottom
		if ((y + 3) < ParsedFile.size())
		{
			output += ParsedFile[y + 1][x];
			output += ParsedFile[y + 2][x];
			output += ParsedFile[y + 3][x];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}
		//Bottom Left
		if ((y + 3) < ParsedFile.size() && (x - 3) >= 0)
		{
			output += ParsedFile[y + 1][x - 1];
			output += ParsedFile[y + 2][x - 2];
			output += ParsedFile[y + 3][x - 3];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}

		//Left
		if ((x - 3) >= 0)
		{
			output += ParsedFile[y][x - 1];
			output += ParsedFile[y][x - 2];
			output += ParsedFile[y][x - 3];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}
		//Top Left
		if ((x - 3) >= 0 && (y - 3) >= 0)
		{
			output += ParsedFile[y - 1][x - 1];
			output += ParsedFile[y - 2][x - 2];
			output += ParsedFile[y - 3][x - 3];

			if (output == wordToFind)
			{
				result++;
			}

			output = "X";
		}
	}

	std::cout << "Result is: " << result << std::endl;
}
void DayFour::RunBonusAssignment()
{
	int result = 0;

	for (size_t i = 0; i < ACoordinates.size(); i++)
	{
		int y = ACoordinates[i].first;
		int x = ACoordinates[i].second;

		if (((y - 1) < 0 || (y + 1) >= ParsedFile.size()) ||
			((x - 1) < 0 || (x + 1) >= ParsedFile[y].size()))
		{
			continue;
		}

		if (((ParsedFile[y + 1][x - 1] == 'M' && ParsedFile[y - 1][x + 1] == 'S') ||
			(ParsedFile[y + 1][x - 1] == 'S') && (ParsedFile[y - 1][x + 1] == 'M')) &&
			(((ParsedFile[y + 1][x + 1] == 'M') && (ParsedFile[y - 1][x - 1] == 'S')) ||
			((ParsedFile[y + 1][x + 1] == 'S') && (ParsedFile[y - 1][x - 1] == 'M'))))
		{
			result++;
		}
	}

	std::cout << "Result is: " << result << std::endl;
}