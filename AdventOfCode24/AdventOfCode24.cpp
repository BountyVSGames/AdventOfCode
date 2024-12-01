// AdventOfCode24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include "DayOne.h"

std::vector<std::string> FileParser(std::string filePath);

int main()
{
    DayOne* dayOne = new DayOne();

    dayOne->RunAssignment(FileParser("Input\\Day1.txt"));
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