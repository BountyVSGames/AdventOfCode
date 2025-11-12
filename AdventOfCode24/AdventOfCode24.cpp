// AdventOfCode24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <chrono>
#include "Days/DayOne.h"
#include "Days/DayTwo.h"
#include "Days/DayThree.h"
#include "Days/DayFour.h"
#include "Days/DayFive.h"
#include "Days/DaySix.h"
#include "Days/DaySeven.h"
#include "Days/DayNine.h"
#include "Days/DayTen.h"
#include "Days/DayEleven.h"

using namespace std::chrono;

std::vector<std::string> FileParser(std::string filePath);
std::vector<Assignment*> AllAssignments;

int main()
{
    //AllAssignments.push_back(new DayOne(FileParser("Input\\Day1.txt")));
    //AllAssignments.push_back(new DayTwo(FileParser("Input\\Day2.txt")));
    //AllAssignments.push_back(new DayThree(FileParser("Input\\Day3.txt")));
    //AllAssignments.push_back(new DayFour(FileParser("Input\\Day4.txt")));
    //AllAssignments.push_back(new DayFive(FileParser("Input\\Day5.txt")));
    //AllAssignments.push_back(new DaySix(FileParser("Input\\Day6.txt")));
    //AllAssignments.push_back(new DaySeven(FileParser("Input\\Day7.txt")));
    //AllAssignments.push_back(new DayNine(FileParser("Input\\Day9.txt")));
    //AllAssignments.push_back(new DayTen(FileParser("Input\\Day10.txt")));
    //AllAssignments.push_back(new DayEleven(FileParser("Input\\Day11.txt")));

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

    for (size_t i = AllAssignments.size(); i-- > 0;)
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