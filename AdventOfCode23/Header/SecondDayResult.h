#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

struct Game
{
	int blue = 0;
	int red = 0;
	int green = 0;
};

class SecondDayResult
{
public:
	SecondDayResult();

	void RunAssignmentPart1();
	void RunAssignmentPart2();
private:
	std::vector<std::string> ParsedFile;
	std::vector<std::vector<Game>> AllGames;
	
	int MaxBlueValue;
	int MaxRedValue;
	int MaxGreenValue;

	void ParseGame(std::string input);

	bool IsGamePossible(std::vector<Game> game);
	int GetNumberFromString(std::string line);
	bool StringContain(const std::string& input, const std::string& compareString);

	Game MaxRoleInGame(std::vector<Game> game);
};