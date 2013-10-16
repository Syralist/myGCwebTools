#ifndef LETTERSYMBOL_H
#define LETTERSYMBOL_H

#include <QObject>
#include <QMap>
#include <QString>

class LetterSymbol : public QObject
{
    Q_OBJECT
public:
    explicit LetterSymbol(QObject *parent = 0);
    
signals:
    
public slots:
    QString toLetter(QString symbol, QString List);
    QString toSymbol(QString letter, QString List);

private:
    QMap<QString, QMap<QString, QString>*> m_Maps;
    QMap<QString, QString> m_MorseCode;
    
};

#endif // LETTERSYMBOL_H
