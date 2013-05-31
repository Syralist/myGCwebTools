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
        char LetterA = 'a';
        for(int i = 0; i < m_sLetters.size(); i++)
        {
            if(m_iDirection == 0)
            {
                m_lNumbers << (int) m_sLetters[i].toLower().toLatin1() - (int) LetterA + 1;
            }
            else
            {
                m_lNumbers << 26 - ((int) m_sLetters[i].toLower().toLatin1() - (int) LetterA);
            }
        }
        for(int i = 0; i < m_lNumbers.size(); i++)
        {
            m_sNumbers.append(QString::number(m_lNumbers.at(i)));
            m_sNumbers.append(" ");
        }
        emit UpdatedNumbers(m_sNumbers);
    }
}

void LetterNumberConverter::setNumbers(QString Numbers)
{
    if(m_iInput == 1)
    {
        m_sNumbers = Numbers;
    }
}
