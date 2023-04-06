#include <QCoreApplication>
#include <QDebug>
#include "dbworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DBWorker::createDB();
    DBWorker::selectFromDB();
    DBWorker::close();

    exit(0);

    return a.exec();
}
