#include "coordinate.h"

Coordinate::Coordinate(QObject *parent) :
    QObject(parent)
{
    m_dDegreeNorth = -53.087117;
    m_dDegreeEast = -8.791817;
    m_sLetterNorth = tr("N");
    m_sLetterSouth = tr("S");
    m_sLetterEast = tr("E");
    m_sLetterWest = tr("W");
}

QString Coordinate::printDegrees()
{
    double dDegreeNorth;
    QString LetterNorth;
    if(m_dDegreeNorth < 0)
    {
        dDegreeNorth = m_dDegreeNorth * -1.;
        LetterNorth = m_sLetterSouth;
    }
    else
    {
        dDegreeNorth = m_dDegreeNorth;
        LetterNorth = m_sLetterNorth;
    }
    double dDegreeEast;
    QString LetterEast;
    if(m_dDegreeEast < 0)
    {
        dDegreeEast = m_dDegreeEast * -1.;
        LetterEast = m_sLetterWest;
    }
    else
    {
        dDegreeEast = m_dDegreeEast;
        LetterEast = m_sLetterEast;
    }
    QString returnValue;
    returnValue.append(LetterNorth);
    returnValue.append(QString::number(dDegreeNorth,'g',8));
    returnValue.append(" ");

    returnValue.append(LetterEast);
    returnValue.append(QString::number(dDegreeEast,'g',8));
    return returnValue;
}

QString Coordinate::printDegreesMinutes()
{
    double dDegreeNorth;
    QString LetterNorth;
    if(m_dDegreeNorth < 0)
    {
        dDegreeNorth = m_dDegreeNorth * -1.;
        LetterNorth = m_sLetterSouth;
    }
    else
    {
        dDegreeNorth = m_dDegreeNorth;
        LetterNorth = m_sLetterNorth;
    }
    double dDegreeEast;
    QString LetterEast;
    if(m_dDegreeEast < 0)
    {
        dDegreeEast = m_dDegreeEast * -1.;
        LetterEast = m_sLetterWest;
    }
    else
    {
        dDegreeEast = m_dDegreeEast;
        LetterEast = m_sLetterEast;
    }
    int iDegreeNorth = dDegreeNorth;
    m_dMinuteNorth = 60 * (dDegreeNorth - (double)iDegreeNorth);

    int iDegreeEast = dDegreeEast;
    m_dMinuteEast = 60 * (dDegreeEast - (double)iDegreeEast);

    QString returnValue;
    returnValue.append(LetterNorth);
    returnValue.append(QString::number(iDegreeNorth));
    returnValue.append(QString::fromUtf8("° "));
    returnValue.append(QString::number(m_dMinuteNorth));
    returnValue.append(" ");

    returnValue.append(LetterEast);
    returnValue.append(QString::number(iDegreeEast));
    returnValue.append(QString::fromUtf8("° "));
    returnValue.append(QString::number(m_dMinuteEast));
    return returnValue;
}

QString Coordinate::printDegressMinutesSeconds()
{
    double dDegreeNorth;
    QString LetterNorth;
    if(m_dDegreeNorth < 0)
    {
        dDegreeNorth = m_dDegreeNorth * -1.;
        LetterNorth = m_sLetterSouth;
    }
    else
    {
        dDegreeNorth = m_dDegreeNorth;
        LetterNorth = m_sLetterNorth;
    }
    double dDegreeEast;
    QString LetterEast;
    if(m_dDegreeEast < 0)
    {
        dDegreeEast = m_dDegreeEast * -1.;
        LetterEast = m_sLetterWest;
    }
    else
    {
        dDegreeEast = m_dDegreeEast;
        LetterEast = m_sLetterEast;
    }
    int iDegreeNorth = dDegreeNorth;
    m_dMinuteNorth = 60 * (dDegreeNorth - (double)iDegreeNorth);
    int iMinuteNorth = m_dMinuteNorth;
    m_dSecondNorth = 60 * (m_dMinuteNorth - (double)iMinuteNorth);

    int iDegreeEast = dDegreeEast;
    m_dMinuteEast = 60 * (dDegreeEast - (double)iDegreeEast);
    int iMinuteEast = m_dMinuteEast;
    m_dSecondEast = 60 * (m_dMinuteEast - (double)iMinuteEast);

    QString returnValue;
    returnValue.append(LetterNorth);
    returnValue.append(QString::number(iDegreeNorth));
    returnValue.append(QString::fromUtf8("° "));
    returnValue.append(QString::number(iMinuteNorth));
    returnValue.append("' ");
    returnValue.append(QString::number(m_dSecondNorth));
    returnValue.append("\" ");

    returnValue.append(LetterEast);
    returnValue.append(QString::number(iDegreeEast));
    returnValue.append(QString::fromUtf8("° "));
    returnValue.append(QString::number(iMinuteEast));
    returnValue.append("' ");
    returnValue.append(QString::number(m_dSecondEast));
    returnValue.append("\" ");
    return returnValue;
}

void Coordinate::updateFromDegrees(QString string)
{
}

void Coordinate::updateFromDegreesMinutes(QString string)
{
}

void Coordinate::updateFromDegreesMinutesSeconds(QString string)
{
}
