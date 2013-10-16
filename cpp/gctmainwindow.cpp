#include "gctmainwindow.h"
#include "ui_gctmainwindow.h"

gctMainWindow::gctMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gctMainWindow),
    m_Coord(this)
{
    ui->setupUi(this);

    connect(ui->CoordMenuButton,SIGNAL(clicked()),this,SLOT(CoordMenuClicked()));
    connect(ui->CoordButtonDegree,SIGNAL(clicked()),this,SLOT(UpdateDegree()));
    connect(ui->CoordButtonDegreeMinute,SIGNAL(clicked()),this,SLOT(UpdateDegreeMinute()));
    connect(ui->CoordButtonDegreeMinuteSecond,SIGNAL(clicked()),this,SLOT(UpdateDegreeMinuteSecond()));

    connect(ui->LetterMenuButton,SIGNAL(clicked()),this,SLOT(LetterMenuClicked()));
    connect(ui->LetterComboInput,SIGNAL(currentIndexChanged(int)),&m_LetterNumberConverter,SLOT(setInput(int)));
    connect(ui->LetterComboDirection,SIGNAL(currentIndexChanged(int)),&m_LetterNumberConverter,SLOT(setDirection(int)));
    connect(ui->LetterSpinOffset,SIGNAL(valueChanged(int)),&m_LetterNumberConverter,SLOT(setOffset(int)));
    connect(ui->LetterLineInput,SIGNAL(textChanged(QString)),&m_LetterNumberConverter,SLOT(setLetters(QString)));
    connect(ui->LetterLineInput,SIGNAL(textChanged(QString)),&m_LetterNumberConverter,SLOT(setNumbers(QString)));
    connect(&m_LetterNumberConverter,SIGNAL(UpdatedLetters(QString)),ui->LetterLineOutput,SLOT(setText(QString)));
    connect(&m_LetterNumberConverter,SIGNAL(UpdatedNumbers(QString)),ui->LetterLineOutput,SLOT(setText(QString)));
    connect(&m_LetterNumberConverter,SIGNAL(UpdatedStatistics(QList<int>&)),this,SLOT(LetterNumberStatistics(QList<int>&)));
    connect(ui->LetterCodesToCode,SIGNAL(clicked()),this,SLOT(LetterToCode()));
    connect(ui->LetterCodesToLetter,SIGNAL(clicked()),this,SLOT(CodeToLetter()));

    connect(ui->NumberMenuButton,SIGNAL(clicked()),this,SLOT(NumberMenuClicked()));

    ui->LetterCodesSelectCode->addItem(tr("Morsecode"),"Morsecode");
    ui->LetterCodesSelectCode->setCurrentIndex(0);

    CoordMenuClicked();
    //LetterMenuClicked();

}

gctMainWindow::~gctMainWindow()
{
    delete ui;
}

void gctMainWindow::PrintCoordinates()
{
    ui->CoordLineDegree->setText(m_Coord.printDegrees());
    ui->CoordLineDegreeMinute->setText(m_Coord.printDegreesMinutes());
    ui->CoordLineDegreeMinuteSecond->setText(m_Coord.printDegressMinutesSeconds());
}

void gctMainWindow::CoordMenuClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CoordPage);
}

void gctMainWindow::LetterMenuClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->LetterPage);
}

void gctMainWindow::NumberMenuClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->NumberPage);
}

void gctMainWindow::UpdateDegree()
{
    m_Coord.updateFromDegrees(ui->CoordLineDegree->text());
    PrintCoordinates();
}

void gctMainWindow::UpdateDegreeMinute()
{
    m_Coord.updateFromDegreesMinutes(ui->CoordLineDegreeMinute->text());
    PrintCoordinates();
}

void gctMainWindow::UpdateDegreeMinuteSecond()
{
    m_Coord.updateFromDegreesMinutesSeconds(ui->CoordLineDegreeMinuteSecond->text());
    PrintCoordinates();
}

void gctMainWindow::LetterNumberStatistics(QList<int> &Statictics)
{
    ui->LetterLineCharacters->setText(QString::number(Statictics.at(0)));
    ui->LetterLineLetters->setText(QString::number(Statictics.at(1)));
    ui->LetterLineLetterSum->setText(QString::number(Statictics.at(2)));
    ui->LetterLineCrossSumLetterSum->setText(QString::number(Statictics.at(3)));
    ui->LetterLineCrossSumLetterSumIterated->setText(QString::number(Statictics.at(4)));
}

void gctMainWindow::LetterToCode()
{
    ui->LetterCodesInputCode->clear();
    QString Letters = ui->LetterCodesInputLetter->text();
    QString Symbols;
    QString SymbolList = ui->LetterCodesSelectCode->itemData(ui->LetterCodesSelectCode->currentIndex()).toString();
    foreach (QString letter, Letters) {
        Symbols.append(m_LetterSymbol.toSymbol(letter,SymbolList));
        Symbols.append(" ");
    }
    ui->LetterCodesInputCode->setText(Symbols);
}

void gctMainWindow::CodeToLetter()
{
    ui->LetterCodesInputLetter->clear();
    QString Symbols = ui->LetterCodesInputCode->text();
    QString Letters;
    QString SymbolList = ui->LetterCodesSelectCode->itemData(ui->LetterCodesSelectCode->currentIndex()).toString();
    foreach (QString symbol, Symbols.split(" ")) {
        Letters.append(m_LetterSymbol.toLetter(symbol,SymbolList));
    }
    ui->LetterCodesInputLetter->setText(Letters);
}
