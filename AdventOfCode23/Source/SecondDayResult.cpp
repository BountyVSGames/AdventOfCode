#include "../Header/SecondDayResult.h"

SecondDayResult::SecondDayResult()
{
	std::string line;
	std::ifstream myfile("CalibrationDocumentDay2.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			ParsedFile.push_back(line);
		}

		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}

	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		ParseGame(ParsedFile[i]);
	}

	MaxRedValue = 12;
	MaxGreenValue = 13;
	MaxBlueValue = 14;
}

void SecondDayResult::RunAssignmentPart1()
{
	size_t possibleCombinations = 0;

	for (size_t i = 0; i < AllGames.size(); i++)
	{
		if (IsGamePossible(AllGames[i]))
		{
			possibleCombinations += i + 1;
		}
	}

	std::cout << "Total combination possible: " << possibleCombinations << std::endl;
}

void SecondDayResult::RunAssignmentPart2()
{
	int powerOfMinCubesInGames = 0;

	for (size_t i = 0; i < AllGames.size(); i++)
	{
		Game maxGame = MaxRoleInGame(AllGames[i]);
		int powerOfMinGamesInRole = 1;

		if (maxGame.blue > 0)
		{
			powerOfMinGamesInRole *= maxGame.blue;
		}
		if (maxGame.red > 0)
		{
			powerOfMinGamesInRole *= maxGame.red;
		}
		if (maxGame.green > 0)
		{
			powerOfMinGamesInRole *= maxGame.green;
		}

		powerOfMinCubesInGames += powerOfMinGamesInRole;
	}

	std::cout << "Sum of the power of all sets: " << powerOfMinCubesInGames << std::endl;
}

void SecondDayResult::ParseGame(std::string input)
{
	std::vector<Game> allRolesInGame;

	input.erase(0, input.find(":") + 2);

	size_t splitGameIndex = 0;

	while (splitGameIndex != std::string::npos)
	{
		Game game;

		size_t nextSplitGameIndex = input.find(";", splitGameIndex + 1);
		std::string roleString = input.substr(splitGameIndex, nextSplitGameIndex - splitGameIndex);

		size_t splitCubeIndex = 0;

		while (splitCubeIndex != std::string::npos)
		{
			size_t nextCubeIndex = roleString.find(",", splitCubeIndex + 1);
			std::string cubeString = roleString.substr(splitCubeIndex, nextCubeIndex - splitCubeIndex);

			if (StringContain(cubeString, "blue"))
			{
				game.blue = GetNumberFromString(cubeString);
			}
			else if (StringContain(cubeString, "red"))
			{
				game.red = GetNumberFromString(cubeString);
			}
			else if (StringContain(cubeString, "green"))
			{
				game.green = GetNumberFromString(cubeString);
			}

			if (nextCubeIndex != std::string::npos)
			{
				splitCubeIndex = nextCubeIndex + 2;
				continue;
			}

			splitCubeIndex = nextCubeIndex;
		}

		allRolesInGame.push_back(game);

		if (nextSplitGameIndex != std::string::npos)
		{
			splitGameIndex = nextSplitGameIndex + 2;
			continue;
		}

		splitGameIndex = nextSplitGameIndex;
	}

	AllGames.push_back(allRolesInGame);
}

bool SecondDayResult::IsGamePossible(std::vector<Game> game)
{
	for (size_t i = 0; i < game.size(); i++)
	{
		if ((game[i].blue > 0 && game[i].blue > MaxBlueValue) ||
			(game[i].red > 0 && game[i].red > MaxRedValue) ||
			(game[i].green > 0 && game[i].green > MaxGreenValue))
		{
			return false;
		}
	}

	return true;
}
int SecondDayResult::GetNumberFromString(std::string line)
{
	int firstValue = 0;
	int secondValue = 0;

	for (int i = 0; i < line.length(); i++)
	{
		if (firstValue == 0 && isdigit(line.at(i)))
		{
			if (isdigit(line.at(i + 1)))
			{
				//'0' is char 48. '1' is char 49. So we subtract from it to convert the char number to a int.
				firstValue = (line[i] - '0') * 10;			
			}
			else
			{
				//'0' is char 48. '1' is char 49. So we subtract from it to convert the char number to a int.
				firstValue = (line[i] - '0');
			}
		}
		else if (isdigit(line.at(i)))
		{
			secondValue = line[i] - '0';
		}
	}

	return firstValue + secondValue;
}
bool SecondDayResult::StringContain(const std::string& input, const std::string& compareString)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		std::string tempString = "";

		for (size_t j = 0; j < compareString.size(); j++)
		{
			if (i + j >= input.size()) 
			{
				return false;
			}

			tempString += input[i + j];

			if (tempString == compareString)
			{
				return true;
			}
		}
	}

	return false;
}

Game SecondDayResult::MaxRoleInGame(std::vector<Game> game)
{
	Game maxRole = Game();

	for (size_t i = 0; i < game.size(); i++)
	{
		if (game[i].blue > maxRole.blue)
		{
			maxRole.blue = game[i].blue;
		}
		
		if (game[i].red > maxRole.red)
		{
			maxRole.red = game[i].red;
		}

		if (game[i].green > maxRole.green)
		{
			maxRole.green = game[i].green;
		}
	}

	return maxRole;
}