#include "gctmainwindow.h"
#include "ui_gctmainwindow.h"

gctMainWindow::gctMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gctMainWindow),
    m_TestCoord(this)
{
    ui->setupUi(this);
    connect(ui->CoordButtonDegree,SIGNAL(clicked()),this,SLOT(PrintCoordinates()));
}

gctMainWindow::~gctMainWindow()
{
    delete ui;
}

void gctMainWindow::PrintCoordinates()
{
    ui->CoordLineDegree->setText(m_TestCoord.printDegrees());
    ui->CoordLineDegreeMinute->setText(m_TestCoord.printDegreesMinutes());
    ui->CoordLineDegreeMinuteSecond->setText(m_TestCoord.printDegressMinutesSeconds());
}
