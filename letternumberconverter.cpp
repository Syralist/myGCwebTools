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
//        m_lStatistics.clear();

//        int NumLetters = 0;
//        int NumChars = 0;
//        int LetterSum = 0;

        LettersToNumbers(m_sLetters, m_lNumbers);
        NumberListToNumberString(m_lNumbers, m_sNumbers);
        CalculateStatistics(m_lStatistics, m_lNumbers);

//        NumLetters = NumOfLetters(m_lNumbers);
//        NumChars = NumOfChars(m_lNumbers);
//        LetterSum = SumOfLetters(m_lNumbers);

//        m_lStatistics << NumChars;
//        m_lStatistics << NumLetters;
//        m_lStatistics << LetterSum;
//        m_lStatistics << CrossSum(LetterSum);
//        m_lStatistics << CrossSumIterated(LetterSum);
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

void LetterNumberConverter::LettersToNumbers(QString &Letters, QList<int> &Numbers)
{
    char LetterA = 'a';
    int iLetterA = (int) LetterA;
    int iLetter = 0;
    int LetterNum = 0;
    for(int i = 0; i < Letters.size(); i++)
    {
        iLetter = (int) Letters[i].toLower().toLatin1();
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
            Numbers << LetterNum;
        }
        else
        {
            Numbers << 0;
        }
    }
}

void LetterNumberConverter::NumberListToNumberString(QList<int> &Numbers, QString &NumberString)
{
    for(int i = 0; i < Numbers.size(); i++)
    {
        NumberString.append(QString::number(Numbers.at(i)));
        NumberString.append(" ");

    }
}

int LetterNumberConverter::NumOfLetters(QList<int> Numbers)
{
    int Num = 0;
    for(int i = 0; i < Numbers.size(); i++)
    {
        if(Numbers.at(i) >= 1 && Numbers.at(i) <= 26)
        {
            Num++;
        }
    }
    return Num;
}

int LetterNumberConverter::NumOfChars(QList<int> Numbers)
{
    return Numbers.size();
}

int LetterNumberConverter::SumOfLetters(QList<int> Numbers)
{
    int Sum = 0;
    for(int i = 0; i < Numbers.size(); i++)
    {
        Sum += Numbers.at(i);
    }
    return Sum;
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

int LetterNumberConverter::CrossSumIterated(int Number)
{
    int IteratedSum = Number;
    do
    {
        IteratedSum = CrossSum(IteratedSum);
    }
    while(IteratedSum >= 10);
    return IteratedSum;
}

void LetterNumberConverter::CalculateStatistics(QList<int> &Statistics, QList<int> &Numbers)
{
    Statistics.clear();

    int NumLetters = 0;
    int NumChars = 0;
    int LetterSum = 0;

    NumLetters = NumOfLetters(Numbers);
    NumChars = NumOfChars(Numbers);
    LetterSum = SumOfLetters(Numbers);

    Statistics << NumChars;
    Statistics << NumLetters;
    Statistics << LetterSum;
    Statistics << CrossSum(LetterSum);
    Statistics << CrossSumIterated(LetterSum);
}
