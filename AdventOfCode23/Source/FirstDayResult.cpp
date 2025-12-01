#include "../Header/FirstDayResult.h"

FirstDayResult::FirstDayResult()
{
    m_totalValueAssignment1 = 0;
    m_totalValueAssignment2 = 0;

    m_numbersInString.push_back("one");
    m_numbersInString.push_back("two");
    m_numbersInString.push_back("three");
    m_numbersInString.push_back("four");
    m_numbersInString.push_back("five");
    m_numbersInString.push_back("six");
    m_numbersInString.push_back("seven");
    m_numbersInString.push_back("eight");
    m_numbersInString.push_back("nine");
}

void FirstDayResult::RunAssignmentPart1()
{
    std::string line;
    std::ifstream myfile("CalibrationDocumentDay1.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            m_totalValueAssignment1 += GetCalibrationValueWithNumbers(line);
        }

        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    std::cout << m_totalValueAssignment1 << std::endl;
}
void FirstDayResult::RunAssignmentPart2()
{
    std::string line;
    std::ifstream myfile("CalibrationDocumentDay1.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            int value = GetCallibrationValueWithLetterAndLetters(line);
            m_totalValueAssignment2 += value;
        }

        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    std::cout << m_totalValueAssignment2 << std::endl;
}

int FirstDayResult::GetCalibrationValueWithNumbers(std::string line)
{
    int firstValue = 0;
    int secondValue = 0;

	for (int i = 0; i < line.length(); i++)
    {
	    if (firstValue == 0 && isdigit(line.at(i)))
	    {
		    //'0' is char 48. '1' is char 49. So we subtract from it to convert the char number to a int.
		    firstValue = (line[i] - '0') * 10;
		    secondValue = line[i] - '0';
	    }
	    else if (isdigit(line.at(i)))
	    {
		    secondValue = line[i] - '0';
	    }
    }

    return firstValue + secondValue;
}
int FirstDayResult::GetCallibrationValueWithLetterAndLetters(std::string line)
{
    int firstValue = 0;
    int secondValue = 0;

    for (int i = 0; i < line.length(); i++)
    {
        CompareString(line);
    }

    return GetCalibrationValueWithNumbers(line);
}

int FirstDayResult::CompareString(std::string& originalString)
{
    int returnIndex = 100;
    int returnValue = 0;
    int returnNumberLetterCount = 0;

    for (int i = 0; i < m_numbersInString.size(); i++)
    {
        size_t index = originalString.find(m_numbersInString[i]);

        if (index != std::string::npos)
        {
            if (index < returnIndex)
            {
                originalString[index + 1] = '0' + (i + 1);
            }
        }
    }

    return returnIndex;
}