// AdventOfCode24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include "DayOne.h"
#include "DayTwo.h"
#include "DayThree.h"

std::vector<std::string> FileParser(std::string filePath);

int main()
{
    DayOne* dayOne = new DayOne(FileParser("Input\\Day1.txt"));
    DayTwo* dayTwo = new DayTwo(FileParser("Input\\Day2.txt"));
    DayThree* dayThree = new DayThree(FileParser("Input\\Day3.txt"));
    
    std::cout << "----------------------------------- First Day -----------------------------------" << std::endl;
    dayOne->RunAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    dayOne->RunBonusAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl << std::endl;

    delete dayOne;

    std::cout << "----------------------------------- Second Day -----------------------------------" << std::endl;
    dayTwo->RunAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    dayTwo->RunBonusAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl << std::endl;

    delete dayTwo;

    std::cout << "----------------------------------- Third Day -----------------------------------" << std::endl;
    dayThree->RunAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    dayThree->RunBonusAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl << std::endl;

    delete dayThree;
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