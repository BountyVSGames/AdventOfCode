#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FirstDayResult
{
public:
	FirstDayResult();

	void RunAssignmentPart1();
	void RunAssignmentPart2();
private:
	int GetCalibrationValueWithNumbers(std::string line);
	int GetCallibrationValueWithLetterAndLetters(std::string line);

	int CompareString(std::string& originalString);

	std::vector<std::string> m_numbersInString;

	std::ifstream m_lineToRead;
	std::ifstream m_fileToRead;

	int m_totalValueAssignment1;
	int m_totalValueAssignment2;
};

