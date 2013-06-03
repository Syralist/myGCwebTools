#ifndef GCTMAINWINDOW_H
#define GCTMAINWINDOW_H

#include <QMainWindow>
#include "coordinate.h"
#include "letternumberconverter.h"

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
    void LetterNumberMenuClicked();
    void PrintCoordinates();
    void LetterNumberStatistics(QList<int> &Statictics);

private:
    Ui::gctMainWindow *ui;
    Coordinate m_TestCoord;
    LetterNumberConverter m_LetterNumberConverter;
};

#endif // GCTMAINWINDOW_H
