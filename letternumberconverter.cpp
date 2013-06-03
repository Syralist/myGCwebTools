#include "letternumberconverter.h"

LetterNumberConverter::LetterNumberConverter(QObject *parent) :
    QObject(parent),
    m_iInput(0),
    m_iDirection(0),
    m_iOffset(0),
    m_bIsValid(false)
{
}

void LetterNumberConverter::setOffset(int Offset)
{
    m_iOffset = Offset;
}

void LetterNumberConverter::setInput(int Input)
{
    m_iInput = Input;
    m_bIsValid = ((m_iInput < 0 || m_iInput > 1) ? false : true);
}

void LetterNumberConverter::setDirection(int Direction)
{
    m_iDirection = Direction;
    m_bIsValid = ((m_iDirection < 0 || m_iDirection > 1) ? false : true);
}

bool LetterNumberConverter::IsValid()
{
    return m_bIsValid;
}

void LetterNumberConverter::setLetters(QString Letters)
{
    if(m_iInput == 0)
    {
        m_sLetters = Letters;
        m_lNumbers.clear();
        m_sNumbers.clear();
        m_lStatistics.clear();
        char LetterA = 'a';
        int iLetterA = (int) LetterA;
        int iLetter = 0;
        int LetterNum = 0;
        int NumLetters = 0;
        int NumChars = 0;
        int LetterSum = 0;
        int CrossSumLetterSumIterated = 0;
        for(int i = 0; i < m_sLetters.size(); i++)
        {
            iLetter = (int) m_sLetters[i].toLower().toLatin1();
            LetterNum = iLetter - iLetterA;
            if(m_iDirection == 0)
            {
                LetterNum = LetterNum + 1;
            }
            else
            {
                LetterNum = 26 - LetterNum;
            }
            if(LetterNum >= 1 && LetterNum <= 26)
            {
                m_lNumbers << LetterNum;
                NumLetters++;
                NumChars++;
            }
            else
            {
                m_lNumbers << 0;
                NumChars++;
            }
        }
        for(int i = 0; i < m_lNumbers.size(); i++)
        {
            m_sNumbers.append(QString::number(m_lNumbers.at(i)));
            m_sNumbers.append(" ");
            LetterSum += m_lNumbers.at(i);
        }
        m_lStatistics << NumChars;
        m_lStatistics << NumLetters;
        m_lStatistics << LetterSum;
        m_lStatistics << CrossSum(LetterSum);
        CrossSumLetterSumIterated = LetterSum;
        do
        {
            CrossSumLetterSumIterated = CrossSum(CrossSumLetterSumIterated);
        }
        while(CrossSumLetterSumIterated >= 10);
        m_lStatistics << CrossSumLetterSumIterated;
        emit UpdatedNumbers(m_sNumbers);
        emit UpdatedStatistics(m_lStatistics);
    }
}

void LetterNumberConverter::setNumbers(QString Numbers)
{
    if(m_iInput == 1)
    {
        m_sNumbers = Numbers;
    }
}

int LetterNumberConverter::CrossSum(int Number)
{
    int Num = Number;
    int dummy = 0;
    int Sum = 0;
    while(1)
    {
        dummy = Num % 10;
        Sum += dummy;
        Num -= dummy;
        Num /= 10;
        if(Num <= 0)
        {
            break;
        }
    }
    return Sum;
}
