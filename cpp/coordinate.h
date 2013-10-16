#ifndef COORDINATE_H
#define COORDINATE_H

#include <QObject>
#include <QStringList>
#include <QString>

class Coordinate : public QObject
{
    Q_OBJECT

public:
    explicit Coordinate(QObject *parent = 0);
    QString printDegrees();
    QString printDegreesMinutes();
    QString printDegressMinutesSeconds();

signals:

public slots:
    void updateFromDegrees(QString string);
    void updateFromDegreesMinutes(QString string);
    void updateFromDegreesMinutesSeconds(QString string);

private:
    double m_dDegreeNorth;
    double m_dDegreeEast;

    double m_dMinuteNorth;
    double m_dMinuteEast;

    double m_dSecondNorth;
    double m_dSecondEast;

    QString m_sLetterNorth;
    QString m_sLetterSouth;
    QString m_sLetterEast;
    QString m_sLetterWest;
};

#endif // COORDINATE_H
