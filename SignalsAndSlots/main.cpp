#include <QCoreApplication>
#include "watercooler.h"
#include <QtCore>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WaterCooler Cooler;

    return a.exec();
}
