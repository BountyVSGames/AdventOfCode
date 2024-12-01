// AdventOfCode24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include "DayOne.h"

std::vector<std::string> FileParser(std::string filePath);

int main()
{
    DayOne* dayOne = new DayOne(FileParser("Input\\Day1.txt"));
    
    std::cout << "----------------------------------- First Day -----------------------------------" << std::endl;
    dayOne->RunAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    dayOne->RunBonusAssignment();
    std::cout << "---------------------------------------------------------------------------------" << std::endl << std::endl;

    delete dayOne;
}

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