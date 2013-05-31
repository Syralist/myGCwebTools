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
    m_sLetters = Letters;
}

void LetterNumberConverter::setNumbers(QString Numbers)
{
    m_sNumbers = Numbers;
}
