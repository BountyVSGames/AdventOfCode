#include "DayFour.h"

DayFour::DayFour(std::vector<std::string> parsedFile)
{
	ParsedFile = parsedFile;
	std::string wordToFind = "XMAS";
	int result = 0;

	for (int y = 0; y < ParsedFile.size(); y++)
	{
		for (int x = 0; x < ParsedFile[y].size(); x++)
		{
			std::string output = "X";

			if (ParsedFile[y][x] == 'X')
			{
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
		}
	}

	std::cout << "Result is: " << result << std::endl;
}
void DayFour::RunAssignment()
{

}
void DayFour::RunBonusAssignment()
{

}