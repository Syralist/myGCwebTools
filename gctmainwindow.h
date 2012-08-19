#ifndef GCTMAINWINDOW_H
#define GCTMAINWINDOW_H

#include <QMainWindow>
#include "coordinate.h"

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
    void PrintCoordinates();

private:
    Ui::gctMainWindow *ui;
    Coordinate m_TestCoord;
};

#endif // GCTMAINWINDOW_H
