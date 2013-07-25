#include <QtWidgets/QApplication>
#include "gctmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gctMainWindow w;
    w.show();

    return a.exec();
}
