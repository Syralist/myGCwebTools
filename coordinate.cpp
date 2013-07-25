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
    QString NorthPart;
    QString EastPart;
    QString PreparedString = string.simplified();

    PreparedString.replace("N ","N",Qt::CaseInsensitive);
    PreparedString.replace("S ","S",Qt::CaseInsensitive);
    PreparedString.replace("E ","E",Qt::CaseInsensitive);
    PreparedString.replace("W ","W",Qt::CaseInsensitive);
    PreparedString.replace(",",".",Qt::CaseInsensitive);
    PreparedString.replace("°","",Qt::CaseInsensitive);

    QStringList Parts = PreparedString.split(' ');
    if(Parts.size() == 2)
    {
        QString FirstPart = Parts.at(0).simplified();
        QString SecondPart = Parts.at(1).simplified();

        if(FirstPart.contains("N",Qt::CaseInsensitive))
        {
            NorthPart = FirstPart.remove("N",Qt::CaseInsensitive);
        }
        else if(FirstPart.contains("S",Qt::CaseInsensitive))
        {
            NorthPart = FirstPart.remove("S",Qt::CaseInsensitive);
            NorthPart.prepend("-");
        }
        else
        {
            NorthPart = FirstPart;
        }
        if(SecondPart.contains("E",Qt::CaseInsensitive))
        {
            EastPart = SecondPart.remove("E",Qt::CaseInsensitive);
        }
        else if(SecondPart.contains("W",Qt::CaseInsensitive))
        {
            EastPart = SecondPart.remove("W",Qt::CaseInsensitive);
            EastPart.prepend("-");
        }
        else
        {
            EastPart = SecondPart;
        }
    }
    else
    {
        return;
    }
    m_dDegreeNorth = NorthPart.toDouble();
    m_dDegreeEast = EastPart.toDouble();
}

void Coordinate::updateFromDegreesMinutes(QString string)
{
    QString NorthDegreePart;
    QString NorthMinutePart;
    bool isSouth;
    QString EastDegreePart;
    QString EastMinutePart;
    bool isWest;
    QString PreparedString = string.simplified();

    PreparedString.replace("N ","N",Qt::CaseInsensitive);
    PreparedString.replace("S ","S",Qt::CaseInsensitive);
    PreparedString.replace("E ","E",Qt::CaseInsensitive);
    PreparedString.replace("W ","W",Qt::CaseInsensitive);
    PreparedString.replace(",",".",Qt::CaseInsensitive);
    PreparedString.replace("°"," ",Qt::CaseInsensitive);
    PreparedString.replace("'"," ",Qt::CaseInsensitive);
    PreparedString = PreparedString.simplified();

    QStringList Parts = PreparedString.split(' ');
    if(Parts.size() == 4)
    {
        QString FirstPart = Parts.at(0).simplified();
        QString SecondPart = Parts.at(1).simplified();
        QString ThirdPart = Parts.at(2).simplified();
        QString FourthPart = Parts.at(3).simplified();

        if(FirstPart.contains("N",Qt::CaseInsensitive))
        {
            NorthDegreePart = FirstPart.remove("N",Qt::CaseInsensitive);
        }
        else if(FirstPart.contains("S",Qt::CaseInsensitive))
        {
            NorthDegreePart = FirstPart.remove("S",Qt::CaseInsensitive);
            isSouth = true;
        }
        else
        {
            NorthDegreePart = FirstPart;
        }
        NorthMinutePart = SecondPart;

        if(ThirdPart.contains("E",Qt::CaseInsensitive))
        {
            EastDegreePart = ThirdPart.remove("E",Qt::CaseInsensitive);
        }
        else if(ThirdPart.contains("W",Qt::CaseInsensitive))
        {
            EastDegreePart = ThirdPart.remove("W",Qt::CaseInsensitive);
            isWest = true;
        }
        else
        {
            EastDegreePart = ThirdPart;
        }
        EastMinutePart = FourthPart;
    }
    else
    {
        return;
    }
    m_dDegreeNorth = NorthDegreePart.toDouble();
    m_dDegreeNorth += NorthMinutePart.toDouble()/60.0;
    if(isSouth)
    {
        m_dDegreeNorth *= -1.0;
    }
    m_dDegreeEast = EastDegreePart.toDouble();
    m_dDegreeEast += EastMinutePart.toDouble()/60.0;
    if(isWest)
    {
        m_dDegreeEast *= -1.0;
    }
    ;
}

void Coordinate::updateFromDegreesMinutesSeconds(QString string)
{
    QString NorthDegreePart;
    QString NorthMinutePart;
    QString NorthSecondPart;
    bool isSouth;
    QString EastDegreePart;
    QString EastMinutePart;
    QString EastSecondPart;
    bool isWest;
    QString PreparedString = string.simplified();

    PreparedString.replace("N ","N",Qt::CaseInsensitive);
    PreparedString.replace("S ","S",Qt::CaseInsensitive);
    PreparedString.replace("E ","E",Qt::CaseInsensitive);
    PreparedString.replace("W ","W",Qt::CaseInsensitive);
    PreparedString.replace(",",".",Qt::CaseInsensitive);
    PreparedString.replace("°"," ",Qt::CaseInsensitive);
    PreparedString.replace("'"," ",Qt::CaseInsensitive);
    PreparedString.replace("\""," ",Qt::CaseInsensitive);
    PreparedString = PreparedString.simplified();

    QStringList Parts = PreparedString.split(' ');
    if(Parts.size() == 6)
    {
        QString FirstPart = Parts.at(0).simplified();
        QString SecondPart = Parts.at(1).simplified();
        QString ThirdPart = Parts.at(2).simplified();
        QString FourthPart = Parts.at(3).simplified();
        QString FifthPart = Parts.at(4).simplified();
        QString SixthPart = Parts.at(5).simplified();

        if(FirstPart.contains("N",Qt::CaseInsensitive))
        {
            NorthDegreePart = FirstPart.remove("N",Qt::CaseInsensitive);
        }
        else if(FirstPart.contains("S",Qt::CaseInsensitive))
        {
            NorthDegreePart = FirstPart.remove("S",Qt::CaseInsensitive);
            isSouth = true;
        }
        else
        {
            NorthDegreePart = FirstPart;
        }
        NorthMinutePart = SecondPart;
        NorthSecondPart = ThirdPart;

        if(FourthPart.contains("E",Qt::CaseInsensitive))
        {
            EastDegreePart = FourthPart.remove("E",Qt::CaseInsensitive);
        }
        else if(FourthPart.contains("W",Qt::CaseInsensitive))
        {
            EastDegreePart = FourthPart.remove("W",Qt::CaseInsensitive);
            isWest = true;
        }
        else
        {
            EastDegreePart = FourthPart;
        }
        EastMinutePart = FifthPart;
        EastSecondPart = SixthPart;
    }
    else
    {
        return;
    }
    m_dDegreeNorth = NorthDegreePart.toDouble();
    m_dDegreeNorth += NorthMinutePart.toDouble()/60.0;
    m_dDegreeNorth += NorthSecondPart.toDouble()/60.0/60.0;
    if(isSouth)
    {
        m_dDegreeNorth *= -1.0;
    }
    m_dDegreeEast = EastDegreePart.toDouble();
    m_dDegreeEast += EastMinutePart.toDouble()/60.0;
    m_dDegreeEast += EastSecondPart.toDouble()/60.0/60.0;
    if(isWest)
    {
        m_dDegreeEast *= -1.0;
    }
    ;
}
