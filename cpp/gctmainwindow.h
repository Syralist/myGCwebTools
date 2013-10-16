#ifndef GCTMAINWINDOW_H
#define GCTMAINWINDOW_H

#include <QMainWindow>
#include "coordinate.h"
#include "letternumberconverter.h"
#include "lettersymbol.h"

namespace Ui {
    class gctMainWindow;
}

class gctMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gctMainWindow(QWidget *parent = 0);
    ~gctMainWindow();

public slots:
    void CoordMenuClicked();
    void LetterMenuClicked();
    void NumberMenuClicked();

    void UpdateDegree();
    void UpdateDegreeMinute();
    void UpdateDegreeMinuteSecond();
    void PrintCoordinates();

    void LetterNumberStatistics(QList<int> &Statictics);

    void LetterToCode();
    void CodeToLetter();

private:
    Ui::gctMainWindow *ui;
    Coordinate m_Coord;
    LetterNumberConverter m_LetterNumberConverter;
    LetterSymbol m_LetterSymbol;
};

#endif // GCTMAINWINDOW_H
