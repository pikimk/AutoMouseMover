#include "mainwindow.h"

#include <QApplication>
#include "patterns.h"


int main(int argc, char *argv[])
{
    Patterns p;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
