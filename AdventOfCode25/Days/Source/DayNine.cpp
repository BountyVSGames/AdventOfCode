#include "../Header/DayNine.h"

DayNine::DayNine(std::vector<std::string> parsedFile) : Assignment(parsedFile)
{

}

void DayNine::Initialize()
{
	for (size_t i = 0; i < ParsedFile.size(); i++)
	{
		std::pair<int, int> coor;
		size_t sepIt = ParsedFile[i].find(',');

		//x
		coor.first = std::stoi(ParsedFile[i].substr(0, sepIt));
		//y
		coor.second = std::stoi(ParsedFile[i].substr(sepIt + 1, ParsedFile[i].size() - sepIt));

		AllCoors.push_back(coor);
	}
}

void DayNine::RunAssignment()
{
	long long largestArea = 0;

	for (size_t i = 0; i < AllCoors.size(); i++)
	{
		for (size_t j = 0; j < AllCoors.size(); j++)
		{
			if (i == j || CombinedExists(AllCoors[i], AllCoors[j]))
			{
				continue;
			}

			if (AllCoors[i].second == AllCoors[j].second)
			{
				continue;
			}		
			if (AllCoors[i].first == AllCoors[j].first)
			{
				continue;
			}

			AllRectangles.push_back(CalculateRectangle(AllCoors[i], AllCoors[j]));
		}
	}

	for (size_t i = 0; i < AllRectangles.size(); i++)
	{
		if (AllRectangles[i].Size > largestArea)
		{
			largestArea = AllRectangles[i].Size;
		}
	}

	std::cout << "Largest area of any rectangle that can be made is: " << largestArea << std::endl;
}

void DayNine::RunBonusAssignment()
{

}

bool DayNine::CombinedExists(std::pair<int, int> first, std::pair<int, int> second)
{
	Rectangle value = Rectangle(first, second, 0);
	return (std::find(AllRectangles.begin(), AllRectangles.end(), value) != AllRectangles.end());
}

Rectangle DayNine::CalculateRectangle(std::pair<int, int> first, std::pair<int, int> second)
{
	Rectangle value;
	value.FirstPos = first;
	value.SecondPos = second;

	int y = first.second;
	int x = first.first;

	long long lenght = 1;
	long long width = 1;

	if (y > second.second)
	{
		lenght += (long long)(y - second.second);
	}
	else if (y < second.second)
	{
		lenght += (long long)(second.second - y);
	}

	if (x > second.first)
	{
		width += (long long)(x - second.first);
	}
	else if (x < second.first)
	{
		width += (long long)second.first - x;
	}

	value.Size = (width * lenght);
	return value;
}