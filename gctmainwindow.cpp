#include "gctmainwindow.h"
#include "ui_gctmainwindow.h"

gctMainWindow::gctMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gctMainWindow),
    m_TestCoord(this)
{
    ui->setupUi(this);
    connect(ui->CoordButtonDegree,SIGNAL(clicked()),this,SLOT(PrintCoordinates()));
    connect(ui->CoordMenuButton,SIGNAL(clicked()),this,SLOT(CoordMenuClicked()));
    connect(ui->LetterNumberMenuButton,SIGNAL(clicked()),this,SLOT(LetterNumberMenuClicked()));
    connect(ui->LetterNumberComboInput,SIGNAL(currentIndexChanged(int)),&m_LetterNumberConverter,SLOT(setInput(int)));
    connect(ui->LetterNumberComboDirection,SIGNAL(currentIndexChanged(int)),&m_LetterNumberConverter,SLOT(setDirection(int)));
    connect(ui->LetterNumberSpinOffset,SIGNAL(valueChanged(int)),&m_LetterNumberConverter,SLOT(setOffset(int)));
    connect(ui->LetterNumberLineInput,SIGNAL(textChanged(QString)),&m_LetterNumberConverter,SLOT(setLetters(QString)));
    connect(ui->LetterNumberLineInput,SIGNAL(textChanged(QString)),&m_LetterNumberConverter,SLOT(setNumbers(QString)));
    connect(&m_LetterNumberConverter,SIGNAL(UpdatedLetters(QString)),ui->LetterNumberLineOutput,SLOT(setText(QString)));
    connect(&m_LetterNumberConverter,SIGNAL(UpdatedNumbers(QString)),ui->LetterNumberLineOutput,SLOT(setText(QString)));

    CoordMenuClicked();
    LetterNumberMenuClicked();
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

void gctMainWindow::CoordMenuClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CoordPage);
}

void gctMainWindow::LetterNumberMenuClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->LetterNumberPage);
}
