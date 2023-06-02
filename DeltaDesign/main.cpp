#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <Singleton.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Singleton::getInstance();

    qApp->setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.show();
    return a.exec();
}
