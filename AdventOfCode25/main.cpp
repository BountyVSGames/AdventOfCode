#include <fstream>
#include <chrono>

#pragma region Days
#include "Days/Header/DayOne.h"
#include "Days/Header/DayTwo.h"
#include "Days/Header/DayThree.h"
#include "Days/Header/DayFour.h"
#include "Days/Header/DayFive.h"
#include "Days/Header/DaySix.h"
#include "Days/Header/DaySeven.h"
#include "Days/Header/DayEight.h"
#pragma endregion

using namespace std::chrono;

std::vector<std::string> FileParser(std::string filePath);
std::vector<Assignment*> AllAssignments;

int main()
{
    //AllAssignments.push_back(new DayOne(FileParser("Input\\DayOne.txt")));
    //AllAssignments.push_back(new DayTwo(FileParser("Input\\DayTwo.txt")));
    //AllAssignments.push_back(new DayThree(FileParser("Input\\DayThree.txt")));
    //AllAssignments.push_back(new DayFour(FileParser("Input\\DayFour.txt")));
    //AllAssignments.push_back(new DayFive(FileParser("Input\\DayFive.txt")));
    //AllAssignments.push_back(new DaySix(FileParser("Input\\DaySix.txt")));
    //AllAssignments.push_back(new DaySeven(FileParser("Input\\DaySeven.txt")));
    AllAssignments.push_back(new DayEight(FileParser("Input\\DayEight.txt")));

    steady_clock::time_point start;
    steady_clock::time_point finish;

    long long duration = 0;

    for (size_t i = 0; i < AllAssignments.size(); i++)
    {
        start = high_resolution_clock::now();

        std::cout << "------------------------------------ " << AllAssignments[i]->GetAssignmentName() << " ------------------------------------" << std::endl;
        AllAssignments[i]->Initialize();
        AllAssignments[i]->RunAssignment();
        std::cout << "---------------------------------------------------------------------------------" << std::endl;
        AllAssignments[i]->RunBonusAssignment();
        std::cout << "---------------------------------------------------------------------------------" << std::endl;

        finish = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(finish - start).count();

        std::cout << "This assignment took " << duration << " miliseconds" << std::endl;
        std::cout << "---------------------------------------------------------------------------------" << std::endl << std::endl;
    }

    for (int i = (int)AllAssignments.size() - 1; i >= 0; i--)
    {
        delete AllAssignments[i];
    }
}

/// <summary>
/// Reads through the file given and return each line as a vector entry
/// </summary>
/// <param name="filePath">Path to txt file to parse</param>
/// <returns>Return vector of strings containing each line per entry</returns>
std::vector<std::string> FileParser(std::string filePath)
{
    std::ifstream currentFile(filePath);
    std::vector<std::string> returnValue;
    std::string tempText;

    while (std::getline(currentFile, tempText))
    {
        returnValue.push_back(tempText);
    }

    return returnValue;
}